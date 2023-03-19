#include<iostream>
#include<vector>
using namespace std;

void heapify(int* arr, int n, int i){
    // we need to know the largest of the node and its child
    int largest = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    if(i!=largest){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int* arr, int n){
    // make max heap
    for (int i = n/2-1; i >=0 ; i--){
        heapify(arr,n,i);
    }

    // extracting elements from heap
    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    return 0;
}
