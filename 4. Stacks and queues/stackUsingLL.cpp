#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stack
{
private:
    node<T> *head;
    node<T> *end;
    int size;

public:
    stack()
    {
        head = NULL;
        end = NULL;
        size = 0;
    }

    void push(T x)
    {
        node<T> *newNode = new node<T>(x);
        if (end == NULL)
        {
            head = newNode;
            end = newNode;
            size++;
            return;
        }
        end->next = newNode;
        end = end->next;
        size++;
    }

    T pop()
    {
        node<T> *temp = head;
        if (end == NULL)
        {
            cout << "Empty stack" << endl;
            return -1;
        }
        if (temp == end)
        {
            size--;
            T returnVal = temp->data;
            head = NULL;
            end = NULL;
            return returnVal;
        }
        while (temp->next != end)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        int returnVal = end->data;
        end = temp;
        size--;
        return returnVal;
    }

    T peek(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "wrong index" << endl;
            return -1;
        }
        node<T> *temp = head;
        while (index--)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    T stackTop()
    {
        if (end == NULL)
        {
            cout << "Empty stack" << endl;
            return -1;
        }
        return end->data;
    }

    bool isEmpty()
    {
        if (end == NULL)
        {
            return true;
        }
        return false;
    }

    int stackSize()
    {
        return size;
    }
};

int main()
{
    cout << "Welcome!" << endl;
    while (1)
    {
        cout << "Would you like to create a new stack? If yes then enter 1 else enter 0" << endl;
        int feedback1;
        cin >> feedback1;
        if (feedback1 == 0)
        {
            break;
        }
        stack<int> *S = new stack<int>();
        while (1)
        {
            cout << "The operations available are:" << endl;
            cout << "1. Push element" << endl
                 << "2. Pop element" << endl
                 << "3. Peek an element at any index" << endl
                 << "4. Get value of the top element of stack" << endl
                 << "5. Check if stack is empty ?" << endl
                 << "6. Check if stack is full" << endl
                 << "7. Get the current stack size" << endl
                 << "8. Exit" << endl;
            cout << "ENTER ANY ONE OPTION" << endl;
            int feedback2;
            cin >> feedback2;
            if (feedback2 == 8)
            {
                break;
            }
            switch (feedback2)
            {
            case 1:
                cout << "Enter the element you wanna push" << endl;
                int element;
                cin >> element;
                S->push(element);
                break;

            case 2:
                cout << S->pop() << endl;
                break;

            case 3:
                cout << "Enter the index you wanna peak: " << endl;
                int index;
                cin >> index;
                cout << S->peek(index) << endl;
                break;

            case 4:
                cout << S->stackTop() << endl;
                break;

            case 5:
                cout << S->isEmpty() << endl;
                break;

            case 6:
                cout << S->stackSize() << endl;
                break;

            default:
                cout << "INVALID ENTRY" << endl;
                break;
            }
        }
    }

    return 0;
}
