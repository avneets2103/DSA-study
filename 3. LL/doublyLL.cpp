#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
    node(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

template <typename T>
class doublyLinkedList
{
public:
    node<T> *head;
    node<T> *end;
    doublyLinkedList()
    {
        head = NULL;
        end = NULL;
    }

    void create()
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
                    newNode->prev = end;
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
    
    void insertDLL(int index ,T x){
        node<T>* newNode = new node<T>(x);
        node<T>* temp = head;
        while(index-1){
            temp=temp->next;
            index--;
        }
        node<T>* nextNode = temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=nextNode;
        nextNode->prev=newNode;
    }

    void deleteDLL(int index){
        node<T>* temp = head;
        while(index-1){
            temp=temp->next;
            index--;
        }
        node<T>* nextNode = temp->next->next;
        temp->next=nextNode;
        nextNode->prev=temp;
    }

    void reverseDLL(){
        node<int>* temp = head;
        while (temp->next!=NULL)
        {
            node<int>* t = temp->next;
            temp->next=temp->prev;
            temp->prev=t;
            temp=t;
        }
        node<int>* t = temp->next;
        temp->next=temp->prev;
        temp->prev=t;
        head=temp;
    }
};



int main()
{
    doublyLinkedList<int>* DLL = new doublyLinkedList<int>();
    DLL->create();
    DLL->display();
    DLL->insertDLL(2,69);
    cout<<endl;
    DLL->display();
    DLL->deleteDLL(2);
    cout<<endl;
    DLL->display();
    DLL->reverseDLL();
    cout<<endl;
    DLL->display();
    return 0;
}
