#include<iostream>
using namespace std;

template <typename T, typename D>
class Pair{
    public:
    T first;
    D second;
};

template <typename T>
class array{
    private:
    T* arr;
    int capacity;
    int top;

    // we take here 3 varaibles that is array itself, capacity to keep track of the size alloted to this array and 
    // top to easily add, remove elements and keep track of till where there is valid data

    // start with top as -1 for the case where array is empty, and capacity starts with 1 memory location only.
    public:
    array(){
        capacity=1;
        top=-1;
        arr = new T[capacity];
    }

    void add(T x){
        // thats how you change the size of a dynamic array
        if(top == capacity-1){
            capacity *= 2;
            T* newArr = new T[capacity];
            for (int i = 0; i <= top; i++)
            {
                newArr[i] = arr[i];
            }
            arr=newArr;
        }
        arr[++top] = x;
    }

    void insert(T x, int index){
        if(index > top+1 || index<0){
            cout<<"Not allowed insertion"<<endl;
            return;
        }
        // thats how you change the size of a dynamic array
        if(top == capacity-1){
            capacity *= 2;
            T* newArr = new T[capacity];
            for (int i = 0; i <= top; i++)
            {
                newArr[i] = arr[i];
            }
            arr=newArr;
        }
        //now shift elements
        for (int i = top+1; i > index; i--)
        {
            arr[i] = arr[i-1];
        }

        //put the element now
        top++;
        arr[index] = x;
    }

    T del(int index){
        //edge cases
        if(top==-1 || index>top || index<0){
            cout<<"Invalid"<<endl;
            return -1;
        }

        //shifting
        int returnVal = arr[index];
        for (int i = index; i < top; i++)
        {
            arr[i] = arr[i+1];
        }
        top--;
        return returnVal;
    }

    int search(T x){
        for (int i = 0; i <= top; i++)
        {
            if(arr[i]==x){
                return i;
            }
        }
    }

    T get(int index){
        if(index>top || index<0 || top==-1){
            cout<<"Invalid"<<endl;
            return -1;
        }
        return arr[index];
    }

    void set(int index, T x){
        if(index>top || index<0 || top==-1){
            cout<<"Invalid"<<endl;
            return; 
        }
        arr[index] = x;
    }

    // we send a pair of min and max, via this we dont gave to traverse multiple time for min and for max
    Pair<T, T>* MaxMin(){
        int minVal = INT32_MAX;
        int maxVal = INT32_MIN;
        for (int i = 0; i <= top; i++)
        {
            if(minVal > arr[i]){
                minVal = arr[i];
            }
            if(maxVal < arr[i]){
                maxVal = arr[i];
            }
        }
        Pair<T, T> * p = new Pair<T,T> ();
        p->first = minVal;
        p->second = maxVal;
        return p;
    } 

    int size(){
        return top+1;
    }

    void reverse(){
        //recursive approach

        //edge case 
        if(this->size()==1 || this->size()==0){
            return;
        }
        //base case
        if(this->size==2){
            swap(arr[0],arr[1]);
            return;
        }

        //basic functioning:
        // swap the last and the first element from arr
        swap(arr[0], arr[top]);
        //make a newArr and then make it start from index 1 of arr, and top 1 less
        array<T>* newArr = new array();
        newArr->arr = this->arr+1;
        newArr->top = this->top-1;
        newArr->reverse();
        // the newArr is reversed and now we just have to fit the 0th and last index at the ends
        newArr->insert(arr[0],0);
        newArr->add(arr[top]);
        arr=newArr;
    }

    void rotate(int x){
        //iterative
        if(top==-1){
            return;
        }
        for (int j = 0; j < x; j++)
        {
            //code for single rotate
            T temp = arr[top];
            for (int i = top; i > 0; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[0]=top;
        }
    }

    bool sortCheck(){
        bool ans = true;
        for (int i = 1; i <= top; i++)
        {
            if(arr[i-1]>arr[i]){
                ans=false;
            }
        }
        return ans;
    }

    void mergingArrays(array<T>* arr2){
        //both this->arr and arr2 are said to be sorted then only they can be merged
        int s1 = top+1;
        int s2 = arr2->arraySize();
        T* farr = new T[s1+s2];
        int p1=0,p2=0,k=0;
        while(p1!=s1-1 || p2 != s2-1){
            if(arr[p1]<arr2->get(p2)){
                farr[k]=arr[p1];
                p1++;
                
            }
            if(arr[p1]>arr2->get(p2)){
                farr[k]=arr2->get(p2);
                p1++;
            }
            if(arr[p1]==arr2->get(p2)){
                farr[k]=arr[p1];
                p1++;
                k++;
                farr[k]=arr2->get(p2);
                p2++;
            }
            k++;
        }
        if(p1==s1-1){
            for (int i = p2; i < s2; i++)
            {
                farr[k]=arr2->get(p2);
                k++;
            }   
        }
        if(p2==s2-1){
            for (int i = p1; i < s1; i++)
            {
                farr[k]=arr[i];
                k++;
            }
        }
        arr=farr;
    }

    bool isPresent(T x){
        for (int i = 0; i <= top; i++)
        {
            if(arr[i]==x){
                return true;
            }
        }
        return false;
    }
    
    void unionfunc(array<T>* arr2){
        for ( int i = 0; i < arr2->arraySize() ; i++)
        {
            if(!isPresent(arr2->get(i))){
                add(arr2->get(i));
            }
        }
    }

    void intersection(array<T>* arr2){
        array<T>* newArr =  new array();
        for ( int i = 0; i < arr2->arraySize() ; i++)
        {
            if(isPresent(arr2->get(i))){
                newArr->add(arr2->get(i));
            }
        }
        arr=newArr;
    }

    void difference(array<T>* arr2){
        for ( int i = 0; i < arr2->arraySize() ; i++)
        {
            if(isPresent(arr2->get(i))){
                del(search(arr2->get(i)));
            }
        }
    }
};

void duplicateSortedArr1(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==arr[i+1]){
            int count = 1;
            while (arr[i+count]==arr[i+count+1])
            {
                count++;
            }
            cout<<arr[i]<<" is repeated "<<count<<" times."<<endl;
            i+=count;
        }
    }
}

pair<int, int>* maxMin(int* arr, int n){
    pair<int, int>* returningPair =  new pair<int, int>;
    int max = INT16_MIN;
    int min = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    returningPair->first=max;
    returningPair->second=min;
    return returningPair;
}

void ducplicateHashmethod(int * arr , int n){
    int max = maxMin(arr,n)->first;
    int min = maxMin(arr,n)->second;
    int* hash = new int[max-min+1];
    for (int i = 0; i < max-min+1; i++)
    {
        hash[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]-min]++;
    }
    for (int i = 0; i < max-min+1; i++)
    {
        if(hash[i]>1){
            cout<<i+min<<" is repeated "<<hash[i]-1<<" times."<<endl;
        }
    }
}

void sumOfElements(int* arr, int n, int sum){
    int max = maxMin(arr,n)->first;
    int min = maxMin(arr,n)->second;
    int* hash = new int[max-min+1];
    for (int i = 0; i < max-min+1; i++)
    {
        hash[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]-min]++;
    }
    for (int i = 0; i < n; i++)
    {
        int num1 = arr[i];
        //num1 + num2 = sum
        hash[num1-min]--;
        if(hash[sum-arr[i]-min]>0 && sum-arr[i]>=min){
            cout<<"The pair is "<<num1<<" and "<<sum-arr[i]<<endl;
        }
    }
}

void sumOfElementsSorted(int* arr, int n, int k){
    int i = 0;
    int j = n-1;
    int sum = arr[i]+arr[j];
    while(i<j){
        int sum = arr[i]+arr[j];
        if(sum>k){
            j--;
        }
        if(sum<k){
            i++;
        }
        if(sum==k){
            cout<<"Pair is: "<<arr[i]<<" and "<<arr[j]<<endl;
            i++;
            j--;
        }
    }
}

int main(){
    return 0;
}
