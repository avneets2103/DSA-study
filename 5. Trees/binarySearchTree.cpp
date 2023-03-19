#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    BSTNode *root;
    BST()
    {
        root = NULL;
    }
    void levelWiseCreate()
    {
        int rootData;
        cout << "Enter the root data: " << endl;
        cin >> rootData;
        root = new BSTNode(rootData);
        queue<BSTNode *> Q;
        Q.push(root);
        while (Q.size() != 0)
        {
            BSTNode *recentNode = Q.front();
            Q.pop();
            cout << "Enter left child of " << recentNode->data << " :";
            int leftData;
            cin >> leftData;
            if (leftData != -1)
            {
                recentNode->left = new BSTNode(leftData);
                Q.push(recentNode->left);
            }
            cout << "Enter the right child of " << recentNode->data << " :";
            int rightData;
            cin >> rightData;
            if (rightData != -1)
            {
                recentNode->right = new BSTNode(rightData);
                Q.push(recentNode->right);
            }
        }
    }

    void levelWisePrintTree()
    {
        queue<BSTNode *> Q;
        Q.push(root);
        while (Q.size() != 0)
        {
            BSTNode *recentNode = Q.front();
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
};

int maxNode(BSTNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int maxVal;
    maxVal = max(root->data, max(maxNode(root->left), maxNode(root->right)));
    return maxVal;
}

int minNode(BSTNode *root)
{
    if (root == NULL)
    {
        return INT16_MAX;
    }
    int minVal;
    minVal = min(root->data, min(minNode(root->left), minNode(root->right)));
    return minVal;
}

BSTNode *insert(int data, BSTNode *root)
{
    if (data == -1)
    {
        return root;
    }
    BSTNode *newNode = new BSTNode(data);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insert(data, root->left);
        }
        else if (data > root->data)
        {
            root->right = insert(data, root->right);
        }
        return root;
    }
    return root;
}

BSTNode *deleteData(int data, BSTNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        int newRootVal;
        if (root->left != NULL)
        {
            newRootVal = maxNode(root->left);
            root->left = deleteData(newRootVal, root->left);
        }
        else
        {
            if (root->right != NULL)
            {
                newRootVal = minNode(root->right);
                root->right = deleteData(newRootVal, root->right);
            }
            else
            {
                return NULL;
            }
        }
        root->data = newRootVal;
        return root;
    }
    if (root->data > data)
    {
        root->left = deleteData(data, root->left);
        return root;
    }
    if (root->data < data)
    {
        root->right = deleteData(data, root->right);
        return root;
    }
    return root;
}

BSTNode *preOrderToBST(int* pre, int preS, int preE)
{
    if (preE >= preS)
    {
        int rootData = pre[preS];
        BSTNode *root = new BSTNode(rootData);
        int leftCount = 0;
        int i = preS + 1;
        while (pre[i] <= rootData)
        {
            leftCount++;
            i++;
        }
        if(leftCount <= 0){
            root->left = NULL;
        }
        else{
        root->left = preOrderToBST(pre, preS + 1, preS + leftCount);
        }
        int rightCount = preE -  preS - leftCount;
        if(rightCount<=0){ 
            root->right= NULL;
        }
        else{
        root->right = preOrderToBST(pre, i, preE);}

        return root;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    BST *bst = new BST();
    bst->levelWiseCreate();
    bst->levelWisePrintTree();
    cout << endl
         << "ITS INSERT TIME" << endl;
    while (1)
    {
        int data;
        cout << "Enter data: " << endl;
        cin >> data;
        if (data == -1)
        {
            break;
        }
        bst->root = insert(data, bst->root);
    }
    bst->levelWisePrintTree();
    cout << endl
         << "ITS DELETE TIME" << endl;
    while (1)
    {
        int data;
        cout << "Enter data: " << endl;
        cin >> data;
        if (data == -1)
        {
            break;
        }
        bst->root = deleteData(data, bst->root);
    }
    bst->levelWisePrintTree();
    BST* bst2 = new BST();
    int size;
    cout<<"Enter the size of the preOrder: "<<endl;
    cin>>size;
    cout<<"Enter pre order data"<<endl;
    int* pre = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin>>pre[i];
    }
    bst2->root = preOrderToBST(pre,0,size-1);
    bst2->levelWisePrintTree();
    return 0;
}
