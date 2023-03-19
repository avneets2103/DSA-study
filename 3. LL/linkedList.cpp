#include <iostream>
using namespace std;

template <typename T>
class node
{
    // what is a linked list node
public:
    T data;        // data of the node
    node *next;    // address of the next node to be stored for traversal
    node(int data) // constructor while making a node
    {
        this->data = data; // provide the data
        next = NULL;       // set the next as by default NULL then change values later if req.
    }
};

template <typename T>
class linkedList // Linked list class using node
{
public:
    node<T> *head; // To point towards the node in the beginning of the LL
    node<T> *end;  // To go to the end of the LL (saves traversal time)

    linkedList()
    { // when we make a new LL we initialise it with NULL for both head and end
        head = NULL;
        end = NULL;
    }
    void create() // taking the LL input using create()
    {
        while (1)
        {
            cout << "Enter LL element's data: " << endl;
            int elementData;
            cin >> elementData;
            if (elementData == -1)
            {
                break;
            }
            else
            {
                node<T> *newNode = new node<T>(elementData);
                if (end != NULL) // in general we just add the new node to the end of the endNode and the update our endNode
                {
                    end->next = newNode;
                    end = newNode;
                }
                if (end == NULL) // if end is NULL means tht LL is empty thus we have to both initialise the head and end to the new node
                {
                    head = newNode;
                    end = newNode;
                }
            }
        }
    }

    void display()
    { // we can display using a while loop
        node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // recursion
    void recursiveDisplay()
    {
        if (head == NULL)
        {
            return;
        }
        cout << head->data << " ";
        linkedList<T> *LL = new linkedList<T>();
        LL->head = head->next;
        LL->end = end;
        LL->recursiveDisplay();
    }

    // while loop
    int nodeCount()
    {
        node<T> *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // via iteration
    T sumOfAllElements()
    {
        node<T> *temp = head;
        int sum = 0;
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    // via iteration
    T maxElement()
    {
        node<T> *temp = head;
        T max = INT32_MIN;
        while (temp != NULL)
        {
            if (temp->data > max)
            {
                max = temp->data;
                temp = temp->next;
            }
        }
    }

    // via recursion
    int searchInLinkedList(T x)
    {
        if (head == NULL)
        {
            return -1;
        }
        if (head->data == x)
        {
            return 0;
        }
        else
        {
            linkedList<T> *LL = new linkedList<T>();
            LL->head = head->next;
            LL->end = end;
            return 1 + LL->searchInLinkedList(x);
        }
    }

    // recursive way
    linkedList<T> *insertLL(T x, int index)
    {
        node<T> *newNode = new node<T>(x);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return this;
        }
        else
        {
            linkedList<T> *LL = new linkedList<T>();
            LL->head = head->next;
            LL->end = end;
            head->next = LL->insertLL(x, index - 1)->head;
            return this;
        }
    }

    // by recursion
    linkedList<T> *deleteLL(int index)
    {
        if (index == 0)
        {
            head = head->next;
            return this;
        }
        else
        {
            linkedList<T> *LL = new linkedList<T>();
            LL->head = head->next;
            LL->end = end;
            head->next = LL->deleteLL(index - 1)->head;
            return this;
        }
    }

    // by recursion
    bool isSorted()
    {
        if (head->next == NULL)
        {
            return true;
        }
        linkedList<T> *LL = new linkedList<T>();
        LL->head = head->next;
        LL->end = end;
        if (LL->isSorted() && head->data < LL->head->data)
        {
            return true;
        }
        return false;
    }
};

node<int> *insertSortedLL(linkedList<int> *LL, int x)
{
    node<int> *head = LL->head;
    node<int> *end = LL->end;
    node<int> *p = head;
    node<int> *q = NULL;
    node<int> *newNode = new node<int>(x);
    while (p != NULL)
    {
        if (q != NULL)
        {
            if (p->data > x && q->data < x)
            {
                q->next = newNode;
                newNode->next = p;
                break;
            }
        }
        else
        {
            if (p->data > x)
            {
                q = newNode;
                newNode->next = p;
                break;
            }
        }
        q = p;
        p = p->next;
    }
    if (x > q->data)
    {
        q->next = newNode;
    }
    return head;
}

// recursion works
node<int> *removeDuplicateSorted(node<int> *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    if (head->next->data == head->data)
    {
        head = head->next;
    }
    head->next = removeDuplicateSorted(head->next);
    return head;
}

// reversing a LL

// iteration
node<int> *reverseLL(node<int> *head)
{
    node<int> *p = NULL;
    node<int> *q = head;
    while (q != NULL)
    {
        node<int> *r = q->next;
        q->next = p;
        node<int> *t = q;
        q = r;
        p = t;
    }
    return p;
}

// recursion
node<int> *reverseLL2(node<int> *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    node<int> *reveresedLL = reverseLL2(head->next);
    node<int> *newHead = reveresedLL;
    while (reveresedLL->next != NULL)
    {
        reveresedLL = reveresedLL->next;
    }
    reveresedLL->next = head;
    head->next = NULL;
    return newHead;
}

void concatenateLL(linkedList<int> *LL1, linkedList<int> *LL2)
{
    node<int> *end1 = LL1->end;
    node<int> *head2 = LL2->head;
    end1->next = head2;
}

node<int> *mergingLL(linkedList<int> *LL1, linkedList<int> *LL2)
{
    node<int> *head1 = LL1->head;
    node<int> *head2 = LL2->head;
    node<int> *newHead = NULL;
    node<int> *temp = NULL;
    // providing newHead
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (newHead == NULL)
            {
                newHead = head1;
                temp = newHead;
                head1 = head1->next;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
        }
        else if (head1->data > head2->data)
        {
            if (newHead == NULL)
            {
                newHead = head2;
                temp = newHead;
                head2 = head2->next;
            }
            else
            {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
        }
        else if (head1->data == head2->data)
        {
            if (newHead == NULL)
            {
                newHead = head1;
                temp = newHead;
                temp->next = head2;
                temp = temp->next;
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
                temp->next = head2;
                temp = temp->next;
                head1 = head1->next;
                head2 = head2->next;
            }
        }
    }
    if (head1 == NULL)
    {
        temp->next = head2;
    }
    else if (head2 == NULL)
    {
        temp->next = head1;
    }
    return newHead;
}

bool loopInLL(node<int> *head)
{
    node<int> *p = head;
    node<int> *q = head;
    while (p != NULL || q != NULL || q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
        {
            return true;
        }
    }
    return false;
}

node<int>* midNode(node<int>* head){
    node<int>* p = head;
    node<int>* q = p;
    if(head==NULL){
        return NULL;
    } 
    if(head->next==NULL){
        return head;
    }
    while(q->next->next!=NULL && q->next!=NULL ){
        p=p->next;
        q=q->next->next;
    }
    return p;
}

int main()
{
    linkedList<int> *LL = new linkedList<int>();
    LL->create();
    LL->display();
    cout << endl;
    LL->recursiveDisplay();
    cout << endl;
    cout << LL->nodeCount() << endl;
    cout << LL->sumOfAllElements() << endl;
    cout << LL->searchInLinkedList(5) << endl;
    LL = LL->insertLL(69, 2);
    LL->display();
    cout << endl;
    LL = LL->deleteLL(2);
    LL->display();
    cout << endl
         << LL->isSorted() << endl;
    LL->head = insertSortedLL(LL, 15);
    LL->display();
    cout << endl;
    LL->head = removeDuplicateSorted(LL->head);
    LL->display();
    cout << endl;
    LL->head = reverseLL(LL->head);
    LL->display();
    cout << endl;
    LL->head = reverseLL2(LL->head);
    LL->display();
    cout << endl;
    linkedList<int> *LL1 = new linkedList<int>();
    // LL1->create();
    // LL1->display();
    cout << endl;
    // LL->head = mergingLL(LL,LL1);
    // LL->display();
    cout<<midNode(LL->head)->data;
    return 0;
}
