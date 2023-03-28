#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool canPlace(vector<vector<int>> board, int n, int r, int j){
    // columns
    for(int i=0; i<r; i++){
        if(board[i][j] == 1){
            return false;
        }
    }

    // diagnol 1
    for (int i = r-1, int k = j-1; i>=0 && k>=0; i--, k--)
    {
        if(board[i][k]==1){
            return false;
        }
    }
    // diagnol 2
    for (int i = r-1, int k = j-1; i>=0 && k<n; i--, k++)
    {
        if(board[i][k]==1){
            return false;
        }
    }
    return true;
}

void printNqueens(vector<vector<int>> board, int n, int r){
    // base case
    if(r>=n){
        // job is done
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    // check in the row
    for (int i = 0; i < n; i++)
    {
        if(canPlace(board, n, r, i)){
            board[r][i] =1;
            printNqueens(board, n, r+1);
            board[r][i]=0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> line(n,0);
        board[i] = line;
    }
    
    return 0;
}
