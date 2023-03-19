#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if(pq.top()>arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    vector<int> retVector;
    for (int i = 0; i < k; i++)
    {
        retVector.push_back(pq.top());
        pq.pop();
    }

    return retVector;
}

int main(){
    return 0;
}
