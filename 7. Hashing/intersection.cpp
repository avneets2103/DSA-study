#include<iostream>
#include<vector>
using namespace std;

#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> hash1;
    for(int i=0; i<n; i++){
        hash1[arr1[i]]++;
    }
    unordered_map<int, int> hash2;
    for(int i=0; i<m; i++){
        hash2[arr2[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if(hash1[arr2[i]]>0 && hash2[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            hash1[arr2[i]]--;
            hash2[arr2[i]]--;
        }
    }
}

int main(){
    return 0;
}
