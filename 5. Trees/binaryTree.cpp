#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class binaryTreeNode
{
public:
    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;
    binaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

binaryTreeNode *create()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode *root = new binaryTreeNode(rootData);
    cout << "Enter left child of " << rootData << endl;
    root->left = create();
    cout << "Enter the right child of " << rootData << endl;
    root->right = create();
    return root;
}

void printTree(binaryTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "-> ";
    if (root->left != NULL)
    {
        cout << root->left->data << " ";
    }
    else
    {
        cout << "  ";
    }
    cout << ",";
    if (root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

binaryTreeNode *levelWiseCreate()
{
    int rootData;
    cout << "Enter the root data: " << endl;
    cin >> rootData;
    binaryTreeNode *root = new binaryTreeNode(rootData);
    queue<binaryTreeNode *> Q;
    Q.push(root);
    while (Q.size() != 0)
    {
        binaryTreeNode *recentNode = Q.front();
        Q.pop();
        cout << "Enter left child of " << recentNode->data << " :";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            recentNode->left = new binaryTreeNode(leftData);
            Q.push(recentNode->left);
        }
        cout << "Enter the right child of " << recentNode->data << " :";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            recentNode->right = new binaryTreeNode(rightData);
            Q.push(recentNode->right);
        }
    }
    return root;
}

void levelWisePrintTree(binaryTreeNode *root)
{
    queue<binaryTreeNode *> Q;
    Q.push(root);
    while (Q.size() != 0)
    {
        binaryTreeNode *recentNode = Q.front();
        Q.pop();
        cout << recentNode->data << ": L:";
        if (recentNode->left != NULL)
        {
            cout << recentNode->left->data << " ";
            Q.push(recentNode->left);
        }
        else
        {
            cout << "  ";
        }
        cout << " , R:";
        if (recentNode->right != NULL)
        {
            cout << recentNode->right->data;
            Q.push(recentNode->right);
        }
        else
        {
            cout << "  ";
        }
        cout << endl;
    }
}

void preOrder(binaryTreeNode *root, vector<int> *arr)
{
    if (root == NULL)
    {
        return;
    }
    arr->push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}

void postOrder(binaryTreeNode *root, vector<int> *arr)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left, arr);
    postOrder(root->right, arr);
    arr->push_back(root->data);
}

void inOrder(binaryTreeNode *root, vector<int> *arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr->push_back(root->data);
    inOrder(root->right, arr);
}

binaryTreeNode *treeUsingInorderAndPreorder(vector<int> *in, vector<int> *pre, int inS, int inE, int preS, int preE)
{
    if (inS <= inE && preS <= preE)
    {
        int rootData = pre->at(preS);
        int rootIndex;
        for (int i = inS; i <= inE; i++)
        {
            if (in->at(i) == rootData)
            {
                rootIndex = i;
                break;
            }
        }
        binaryTreeNode *root = new binaryTreeNode(rootData);
        int countOfLeftElements = rootIndex - inS;
        int countOfRightElements = inE - rootIndex;
        if(countOfLeftElements==0){
            root->left=NULL;
        }
        else{
            root->left = treeUsingInorderAndPreorder(in, pre, inS, rootIndex - 1, preS + 1, preS + rootIndex);
        }
        if (countOfRightElements==0)
        {
            root->right=NULL;
        }
        else{
            root->right = treeUsingInorderAndPreorder(in, pre, rootIndex + 1, inE, preE - countOfRightElements + 1, preE);
        }
        
        return root;
    }
}

int main()
{
    binaryTreeNode *root = levelWiseCreate();
    levelWisePrintTree(root);
    vector<int> *preOrderArr = new vector<int>{};
    vector<int> *postOrderArr = new vector<int>{};
    vector<int> *inOrderArr = new vector<int>{};
    preOrder(root, preOrderArr);
    postOrder(root, postOrderArr);
    inOrder(root, inOrderArr);
    cout << "PREORDER: " << endl;
    for (int i = 0; i < preOrderArr->size(); i++)
    {
        cout << preOrderArr->at(i) << " ";
    }
    cout << endl
         << "POSTORDER: " << endl;
    for (int i = 0; i < postOrderArr->size(); i++)
    {
        cout << postOrderArr->at(i) << " ";
    }
    cout << endl
         << "INORDER: " << endl;
    for (int i = 0; i < inOrderArr->size(); i++)
    {
        cout << inOrderArr->at(i) << " ";
    }
    cout << endl;
    int nodeCount = inOrderArr->size();
    binaryTreeNode *root2 = treeUsingInorderAndPreorder(inOrderArr, preOrderArr, 0, nodeCount - 1, 0, nodeCount - 1);
    levelWisePrintTree(root2);
    return 0;
}
