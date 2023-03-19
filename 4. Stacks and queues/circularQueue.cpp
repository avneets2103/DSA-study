#include <iostream>
using namespace std;

#define MAX 5
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
        // start with -1 both
        rear = -1;
        front = -1;
        size = 0;
    }

    void enqueue(T x)
    {
        // the case where rear is at end of queue
        if (rear == MAX - 1)
        {
            // here the queue is actually full
            if (front == 0)
            {
                cout << "Queue is full" << endl;
                return;
            }

            // resetting rear
            else
            {
                rear = 0;
                arr[rear] = x;
                size++;
                return;
            }
        }

        // we havent started yet and initialising is req
        if (front == -1)
        {
            front++;
            rear++;
            arr[rear] = x;
            size++;
            return;
        }

        // in general case where we inc rear and then allot the value to the array
        arr[++rear] = x;
        size++;
    }

    T dequeue()
    {
        // since we maintained the size member, its easy to know if queue is empty or not
        if (size == 0)
        {
            cout << "Empty queue" << endl;
            return -1;
        }
        // case when front reaches the end
        if (front == MAX - 1)
        {
            T val = arr[MAX - 1];
            // reset front to 0
            front = 0;
            size--;
            return val;
        }

        // general case where we pop the value and then increase the value of front
        T val = arr[front];
        front++;
        size--;
        return val;
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
        if (size == MAX)
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
        if (size == 0)
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
        if (size == 0)
        {
            return;
        }

        // normal case
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        // front to end and 0 to rear elements are full
        else
        {
            for (int i = front; i < MAX; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
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
