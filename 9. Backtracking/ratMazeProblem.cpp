#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix){
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<endl;    
}

void ratMazeProblem(vector<vector<int>> &path, vector<vector<int>> &maze, int n, int i, int j){
    if(i<0 || j<0 || i>=n || j>=n){
        return;
    }
    if(maze[i][j]==0 || path[i][j]==1){
        return;
    }
    if(i==n-1 && j == n-1){
        path[i][j]=1;
        printMatrix(path);
        return;
    }

    // when we come to a point we include it in the path
    path[i][j] = 1;
    ratMazeProblem(path, maze, n, i-1, j);
    ratMazeProblem(path, maze, n, i+1, j);
    ratMazeProblem(path, maze, n, i, j-1);
    ratMazeProblem(path, maze, n, i, j+1);
    path[i][j]=0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> path(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> line (n,0);
        path[i] = line;
    }
    return 0;
}
