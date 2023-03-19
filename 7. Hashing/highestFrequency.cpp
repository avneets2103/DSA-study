#include<iostream>
#include<vector>
using namespace std;

#include <unordered_map>

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> countMap;
    for(int i=0; i<n; i++){
        if(countMap.count(arr[i])>0){
            countMap[arr[i]]++;
        }
        else{
            countMap[arr[i]]=1;
        }
    } 

    int max = arr[0];
    for(int i=1; i<n; i++){
        if(countMap[arr[i]]>countMap[max]){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    return 0;
}
