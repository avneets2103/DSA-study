#include <iostream>
using namespace std;

class trio
{
public:
    int row;
    int col;
    int element;
    void setElement(int row, int col, int element)
    {
        this->row = row;
        this->col = col;
        this->element = element;
    }
};

class sparceMatrix
{
public:
    int count; // count of non zero elements
    trio *arr;
    int **A;
    int n; // number of cols
    int m; // number of rows
    sparceMatrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        A = new int *[m];
    }
    void create()
    {
        cout << "Enter the number of non zero elements: " << endl;
        int x;
        cin >> x;
        this->count = x;
        // filling the table
        arr = new trio[count + 1];
        for (int i = 1; i <= x; i++)
        {
            cout << "Enter element: " << endl;
            int element;
            cin >> element;
            cout << "Enter the row: " << endl;
            int row;
            cin >> row;
            cout << "Enter the col: " << endl;
            int col;
            cin >> col;
            arr[i].setElement(row, col, element);
        }
        arr[0].row = m;
        arr[0].col = n;
        arr[0].element = count;
    }
    void display()
    {
        // making the array
        for (int i = 0; i < m; i++)
        {
            A[i] = new int[n];
        }

        // setting all zero first
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = 0;
            }
        }

        // filling with the table in the matrix
        for (int i = 1; i <= count; i++)
        {
            A[(arr[i].row) - 1][(arr[i].col) - 1] = arr[i].element;
        }

        // printing
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    sparceMatrix* add(sparceMatrix *B)
    {
        int count2 = B->count;
        trio *arr2 = B->arr;
        trio *arr3 = new trio[count + count2 + 1];
        int i = 1;
        int j = 1;
        int k = 1;
        while (1)
        {
            if (i <= count && j <= count2)
            {
                if (arr[i].row > arr2[j].row)
                {
                    arr3[k] = arr2[j];
                    j++;
                }
                else if (arr[i].row < arr2[j].row)
                {
                    arr3[k] = arr[i];
                    i++;
                }
                else
                {
                    if (arr[i].col > arr2[j].col)
                    {
                        arr3[k] = arr2[j];
                        j++;
                    }
                    else if (arr[i].col < arr2[j].col)
                    {
                        arr3[k] = arr[i];
                        i++;
                    }
                    else
                    {
                        arr3[k].col = arr[i].col;
                        arr3[i].row = arr[i].row;
                        arr3[i].element = arr[i].element + arr2[j].element;
                        i++;
                        j++;
                    }
                }
                k++;
            }
            else
            {
                if (i > count)
                {
                    while (j <= count2)
                    {
                        arr3[k] = arr2[j];
                        j++;
                        k++;
                    }
                }
                else if(j>count2){
                    while(i <= count){
                        arr3[k]=arr[i];
                        i++;
                        k++;
                    }
                }
            }
        }
        sparceMatrix* finalMatrix = new sparceMatrix(n,m);
        finalMatrix->arr=arr3;
        finalMatrix->count=count+count2;
        return finalMatrix;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    sparceMatrix *matrix = new sparceMatrix(n, m);
    sparceMatrix * matrix2 = new sparceMatrix(n,m);
    matrix->create();
    matrix->display();
    matrix2->create();
    matrix2->display();
    sparceMatrix* finalMatrix = matrix2->add(matrix);
    finalMatrix ->display();
    return 0;
}
