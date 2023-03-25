#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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

    int max = INT32_MIN;
    unordered_map<int, int> :: iterator it = countMap.begin();
    while(it!=countMap.end()){
        if(it->second > max){
            max=it->second;
        }
        it++;
    }
    return max;
}

int main(){
    return 0;
}
