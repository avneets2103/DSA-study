#include <iostream>
using namespace std;

#define MAX 100
template <typename T>
class queue
{
private:
    T arr[MAX];
    int front;
    int rear;
    int size;

public:
    queue()
    {
        rear = -1;
        front = -1;
        size = 0;
    }

    void enqueue(T x)
    {
        if (rear >= MAX - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
            size++;
            return;
        }
        arr[++rear] = x;
        size++;
    }

    T dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Empty queue" << endl;
            return -1;
        }
        T returnData = arr[front];
        front++;
        size--;
        return returnData;
    }

    bool isEmpty()
    {
        if (size > 0)
        {
            return false;
        }
        return true;
    }

    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        return false;
    }

    T first()
    {
        if (front > -1 || front <= rear)
        {
            return arr[front];
        }
        cout << "Empty stack";
        return -1;
    }

    T last()
    {
        if (rear < front)
        {
            cout << "Empty stack";
            return -1;
        }
        return arr[rear];
    }

    int queueSize()
    {
        return size;
    }

    void display()
    {
        if (front < 0 || front > rear)
        {
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Welcome!" << endl;
    while (1)
    {
        cout << "Would you like to create a new queue? If yes then enter 1 else enter 0" << endl;
        int feedback1;
        cin >> feedback1;
        if (feedback1 == 0)
        {
            break;
        }
        queue<int> *Q = new queue<int>();
        while (1)
        {
            cout << "The operations available are:" << endl;
            cout << "1. Insert element" << endl
                 << "2. Delete element" << endl
                 << "3. Get value of the front element of queue" << endl
                 << "4. Get value of the last element of queue" << endl
                 << "5. Check if queue is empty ?" << endl
                 << "6. Check if queue is full" << endl
                 << "7. Get the current queue size" << endl
                 << "8. Display the whole queue" << endl
                 << "9. Exit" << endl;
            cout << "ENTER ANY ONE OPTION" << endl;
            int feedback2;
            cin >> feedback2;
            if (feedback2 == 9)
            {
                break;
            }
            switch (feedback2)
            {
            case 1:
                cout << "Enter the element you wanna push" << endl;
                int element;
                cin >> element;
                Q->enqueue(element);
                break;

            case 2:
                cout << Q->dequeue() << endl;
                break;

            case 3:
                cout << Q->first() << endl;
                break;

            case 4:
                cout << Q->last() << endl;
                break;

            case 5:
                cout << Q->isEmpty() << endl;
                break;

            case 6:
                cout << Q->isFull() << endl;
                break;

            case 7:
                cout << Q->queueSize() << endl;
                break;

            case 8:
                Q->display();
                break;

            default:
                cout << "INVALID ENTRY" << endl;
                break;
            }
        }
    }
    return 0;
}
