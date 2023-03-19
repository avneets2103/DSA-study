#include <iostream>
using namespace std;

class digMatrix
{
private:
    int size;
    int *arr = new int[size];
    int **A = new int *[size];

public:
    digMatrix(int size, int *arr)
    {
        this->arr = arr;
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            A[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    A[i][j] = arr[i];
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
    }

    void setElement(int a, int x)
    {
        A[a][a] = x;
    }

    int getElement(int i, int j)
    {
        return A[i][j];
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout<<"Enter size of dig matrix: "<<endl;
    int n;
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the diagnol elements :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    digMatrix* A = new digMatrix(n,arr);
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
            cout<<"At what location do you wanna make changes ?"<<endl;
            int a;
            cin>>a;
            cout<<"Enter new element "<<endl;
            int newElement;
            cin>>newElement;
            A->setElement(a,newElement);
        }
    }
    return 0;
}
