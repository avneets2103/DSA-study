#include<iostream>
#include<vector>
using namespace std;

class PriotrityQueues
{
private:
    vector<int> heap;

public:
    PriotrityQueues(){};
    int getMin()
    {
        if (!heap.size())
        {
            return -1;
        }
        return heap[0];
    }

    // swap till you make it
    void insert(int n)
    {
        heap.push_back(n);
        int i = heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] <= heap[i])
            {
                break;
            }
            else
            {
                swap(heap[p], heap[i]);
                i = p;
            }
        }
    }

    // del the top and replace with the last...then swappy swappy
    void dequeue()
    {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        int i = 0;
        while (i < heap.size() - 1 && (2 * i + 1 <= heap.size() - 1))
        {
            if (2 * i + 2 > heap.size() - 1)
            {
                if (heap[i] > heap[2 * i + 1])
                {
                    swap(heap[i], heap[2 * i + 1]);
                }
                break;
            }
            else
            {
                if (heap[i] <= min(heap[2 * i + 1], heap[2 * i + 2]))
                {
                    break;
                }
                else
                {
                    if (heap[2 * i + 1] < heap[2 * i + 2])
                    {
                        swap(heap[i], heap[2 * i + 1]);
                        i = 2 * i + 1;
                    }
                    else
                    {
                        swap(heap[i], heap[2 * i + 2]);
                        i = 2 * i + 2;
                    }
                }
            }
        }
    }

    int peek()
    {
        if (!heap.size())
        {
            return -1;
        }
        return heap[0];
    }
};

void heapSort(vector<int> &arr){
    PriotrityQueues pq;

    // nLogn for isnerting all
    for (int i = 0; i < arr.size(); i++)
    {
        pq.insert(arr[i]);
    }

    // another nLogn for deleting all elements from it
    vector<int> newArr;
    for (int i = 0; i < arr.size(); i++)
    {
        newArr.push_back(pq.peek());
        pq.dequeue();
    }
    
    arr=newArr;
}

int main(){
    return 0;
}
