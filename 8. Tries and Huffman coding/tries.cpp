#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode** children;

    TrieNode(char data){
        this->data=data;
        isTerminal = false;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
    }
};

class Tries{
    TrieNode* root;

    public:
    Tries(){
        root = new TrieNode('\0');
    }

    // insertion
    void insertH(TrieNode* root, string word){
        // base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // basic calculation
        int index = word[0]-'a';
        TrieNode* childNode;
        if(root->children[index] != NULL){
            childNode = root->children[index];
        }
        else{
            childNode = new TrieNode(word[0]);
            root->children[index] = childNode;
        }

        // recursion
        insertH(childNode, word.substr(1));
    }
    void insert(string word){
        insertH(root, word);
    }

    //searching
    bool searchH(TrieNode* root, string word){
        // base case
        if(word.size()==0){
            return root->isTerminal;
        }

        // basic calcluation
        int index = word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }

        //recursion
        return searchH(root->children[index], word.substr(1));
    }
    bool search(string word){
        return searchH(root,word);
    }

    //remove and deallocate
    void removeH(TrieNode* root, string word){
        // if DNE
        if(!searchH(root, word)){
            return;
        }

        // base case
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }

        // basic calculations
        int index = word[0]-'a';
        removeH(root->children[index], word.substr(1));

        // deallocation of useless nodes // we as parents check for children node if its useless
        // useless means its non terminal and has no child too
        if(!root->children[index]->isTerminal){
            for (int i = 0; i < 26; i++)
            {
                if(root->children[index]->children[i]!=NULL){
                    return;
                }
            }
            delete root->children[index];
            root->children[index] = NULL;
        }
    }
    void remove(string word){
        removeH(root, word);
    }

};

int main(){
    return 0;
}
