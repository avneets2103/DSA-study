#include<iostream>
#include<vector>
using namespace std;

#include<unordered_map>
int pairSum(int *arr, int n) {
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
		if(arr[i]==0){
			count+=((hash[arr[i]]*(hash[arr[i]]-1))/2); //nC2
			hash[arr[i]]=0;
			continue;
		}
		int inverse = -1*arr[i];
        if(hash[inverse] > 0){
            count+=hash[inverse]*hash[arr[i]];
            hash[inverse]=0;
            hash[arr[i]]=0;
        }
    }
    return count;
}

int main(){
    return 0;
}
