#include <iostream>
#include <vector>
using namespace std;

// type: max value, more priority
class PriorityQueue
{
private:
    vector<int> pq;

public:
    bool isEmpty(){return (pq.size() == 0);}

    int getSize(){return pq.size();}

    int getMax(){
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    // swap till you make it
    void insert(int n)
    {
        pq.push_back(n);
        int i = pq.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (pq[p] >= pq[i])
            {
                break;
            }
            else
            {
                swap(pq[p], pq[i]);
                i = p;
            }
        }
    }

    // del the top and replace with the last...then swappy swappy
    int removeMax()
    {
        int val = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int i = 0;
        while (i < pq.size() - 1 && (2 * i + 1 <= pq.size() - 1))
        {
            if (2 * i + 2 > pq.size() - 1)
            {
                if (pq[i] < pq[2 * i + 1])
                {
                    swap(pq[i], pq[2 * i + 1]);
                }
                break;
            }
            else
            {
                if (pq[i] >= min(pq[2 * i + 1], pq[2 * i + 2]))
                {
                    break;
                }
                else
                {
                    if (pq[2 * i + 1] > pq[2 * i + 2])
                    {
                        swap(pq[i], pq[2 * i + 1]);
                        i = 2 * i + 1;
                    }
                    else
                    {
                        swap(pq[i], pq[2 * i + 2]);
                        i = 2 * i + 2;
                    }
                }
            }
        }
        return val;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
