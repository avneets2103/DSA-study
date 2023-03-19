#include<iostream>
using namespace std;

class AVLNode{
    public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int balanceFactor();
};

int height(AVLNode* node){
    if(node==NULL){
        return 0;
    }
    return 1 + max(height(node->left),height(node->right));
}

int AVLNode :: balanceFactor(){
    if(this==NULL){
        return 0;
    }
    return height(this->left) - height(this->right);
}

//all rotations
AVLNode* LLRotation(AVLNode* node){
    if(node==NULL || node -> left==NULL || node->left->left == NULL){
        return NULL;
    }

    AVLNode* n1 = node;
    AVLNode* n2 = n1->left;
    AVLNode* a = n1->right;
    AVLNode* n3 = n2->left;
    AVLNode* b = n2->right;
    AVLNode* d = n3->left;
    AVLNode* c = n3->right;

    n1->left = b;
    n2->right = n1;

    return n2;
}

AVLNode* RRRotation(AVLNode* node){
    if(node==NULL || node -> right==NULL || node->right->right == NULL){
        return NULL;
    }

    AVLNode* n1 = node;
    AVLNode* a = n1->left;
    AVLNode* n2 = n1->right;
    AVLNode* b = n2->left;
    AVLNode* n3 = n2->right;
    AVLNode* c = n3->left;
    AVLNode* d = n3->right;

    n1->right = b;
    n2->left = n1;

    return n2;
}

AVLNode* LRRotation(AVLNode* node){
    if(node==NULL || node -> left==NULL || node->left->right == NULL){
        return NULL;
    }

    AVLNode* n1 = node;
    AVLNode* a = n1->right;
    AVLNode* n2 = n1->left;
    AVLNode* b = n2->left;
    AVLNode* n3 = n2->right;
    AVLNode* c = n3->left;
    AVLNode* d = n3->right;

    n2->right = c;
    n1->left = d;
    n3->left = n2;
    n3->right = n1;
    return n3;   
}

AVLNode* RLRotation(AVLNode* node){
    if(node==NULL || node -> right==NULL || node->right->left == NULL){
        return NULL;
    }

    AVLNode* n1 = node;
    AVLNode* n2 = n1->right;
    AVLNode* a = n1->left;
    AVLNode* n3 = n2->left;
    AVLNode* b = n2->right;
    AVLNode* c = n3->left;
    AVLNode* d = n3->right;

    n1->right = c;
    n2->left = d;
    n3->left = n1;
    n3->right = n2;
    return n3;   
}

int main(){
    return 0;
}
