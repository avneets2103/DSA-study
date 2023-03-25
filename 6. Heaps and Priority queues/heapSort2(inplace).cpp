#include<iostream>
#include<vector>
using namespace std;

void heapSort(int input[], int n){
    // Build heap
    // we are inserting elements in the heap one by one like insertion sort
    for (int i = 1; i < n; i++){
        int childIndex = i;
        while (childIndex>0)
        {
            int parentIndex = (childIndex-1)/2;
            if(input[childIndex]<input[parentIndex]){
                swap(input[childIndex], input[parentIndex]);
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }   
    }

    // swapping so tht it gets sorted
    for (int i = n-1; i > 0; i--)
    {
        swap(input[0], input[i]);
        int k = 0;
        while(k<i && (2*k+1)<=i){
            if (2 * k + 2 > i)
            {
                if (input[k] < input[2 * k + 1])
                {
                    swap(input[k], input[2 * k + 1]);
                }
                break;
            }
            else
            {
                if (input[k] >= max(input[2 * k + 1], input[2 * k + 2]))
                {
                    break;
                }
                else
                {
                    if (input[2 * k + 1] > input[2 * k + 2])
                    {
                        swap(input[k], input[2 * k + 1]);
                        k = 2 * k + 1;
                    }
                    else
                    {
                        swap(input[k], input[2 * k + 2]);
                        k = 2 * k + 2;
                    }
                }
            }
        }
    }
    
}

int main(){
    return 0;
}
