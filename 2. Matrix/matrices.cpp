#include<iostream>
using namespace std;

void getDigMatrix(int** A, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< A[i][j] <<" ";
        }
        cout<<endl;
    }
}

int** setDigMatrix(int* arr, int n){
    int** A = new int*[n];
    for (int i = 0; i < n; i++)
    {
        A[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            if(i==j){
                A[i][j]=arr[i];
            }
            else{
                A[i][j]=0;
            }
        }
    }
    return A;
}

int main(){
    cout<<"Enter the size of the matrix: "<<endl;
    int n,m;
    cin>>n>>m;
    //diagnol matrix
    if(m==n){
        int* arr =  new int [n];
        cout<<"Enter the diagnol elements of the dig array: "<<endl; 
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<"The array is: "<<endl;
        int** A = setDigMatrix(arr,n);
        getDigMatrix(A,n);
    }
    return 0;
}
