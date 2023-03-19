#include <iostream>
using namespace std;

class lowerTriangleMatrix
{
private:
    int n;
    int **A = new int *[n];

public:
    lowerTriangleMatrix(int n, int *arr)
    {
        this->n = n;
        int arrSize = ((n+1)*n) / 2;
        for (int i = 0; i < n; i++)
        {
            A[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                {
                    A[i][j] = 0;
                }
                else 
                {
                    //letting row mapping
                    int location = ((i+1)*i)/2 + j;
                    A[i][j]=arr[location];
                    // if column mapped
                    // int location =  (n+1)*(j-1) - ((j*(j-1))/2) + (i-j)
                }
            }
        }

    }

    void setElement(int x, int i , int j){
        A[i][j]=x;
    }

    int getElement(int i, int j){
        return A[i][j];
    }

    void display(){
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    cout<<"Enter size of dig matrix: "<<endl;
    int n;
    cin>>n;
    int arrSize = ((n+1)*n)/2;
    int* arr = new int[arrSize];
    cout<<"Enter the diagnol elements :"<<endl;
    for (int i = 0; i < arrSize; i++)
    {
        cin>>arr[i];
    }
    lowerTriangleMatrix* A = new lowerTriangleMatrix(n,arr);
    while(1){
        cout<<"Options available are: ";
        cout<<endl;
        cout<<"1.Display the matrix"<<endl<<"2.Make changes in the matrix"<<endl<<"3.Exit"<<endl;
        int option;
        cout<<"Enter one option number: "<<endl;
        cin>>option;
        if(option==3){
            cout<<"Thank you";
            break;
        }
        else if(option==1){
            A->display();
        }
        else{
            cout<<"At what location do you wanna make changes ?"<<endl<<"Enter i :"<<endl;
            int i;
            cin>>i;
            cout<<"Enter j :"<<endl;
            int j;
            cin>>j;
            cout<<"Enter new element "<<endl;
            int newElement;
            cin>>newElement;
            A->setElement(newElement,i,j);
        }
    }
    return 0;
}
