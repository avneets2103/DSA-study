// an array where we already know that the max displacement of any element between the og array and sorted array is k-1.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//works with sliding window technique
void kSortedArray(int arr[], int k, int n){

    // push first k to pq
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // j for array index
    int j = 0;

    //we remove the top element(max) and add the next element
    for (int i = k; i < n; i++)
    {
        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    // since after this the last k elements will be left in the pq, thus we remove them and add to array
    while(pq.empty()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    return 0;
}
