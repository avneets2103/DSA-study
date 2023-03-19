#include <iostream>
using namespace std;

#define MAX 100
template <typename T>
// stack with max capacity of 100
class stack
{
private:
    T arr[MAX];
    int top;
    int size;

public:
    stack()
    {
        top = -1;
        size = 0;
    }

    void push(T x)
    {
        if (top < MAX - 1)
        {
            size++;
            arr[++top] = x;
        }
        else
        {
            cout << "Stack overflow, element not added" << endl;
        }
    }

    T pop()
    {
        if (top > -1)
        {
            size--;
            return arr[top--];
        }
        else
        {
            // cout << "Empty stack, cant pop anything. Returning -1." << endl;
            return -1;
        }
    }

    T peek(int index)
    {
        if (index > top || index < 0)
        {
            cout << "Invalid entry" << endl;
            return -1;
        }
        else
        {
            return arr[index];
        }
    }

    T stackTop()
    {
        if (top == -1)
        {
            cout << "Empty stack" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        if (top > -1)
        {
            return false;
        }
        return true;
    }

    bool isFull()
    {
        if (top < MAX - 1)
        {
            return false;
        }
        return true;
    }

    int stackSize()
    {
        return size;
    }
};

// just push it in the stack whenever we find a ( and pop from the stack whenever we find a ) if at the end of the process there is a mismatches ( in the stack


//parenthesis matching code
int sizeOfString(char *exp)
{
    int count = 0;
    while (exp[count] != '\0')
    {
        count++;
    }
    return count;
}

bool parenthesisMatch(char *exp)
{
    stack<char> *S = new stack<char>();
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            S->push('(');
        }
        if (exp[i] == ')')
        {
            S->pop();
        }
        i++;
    }

    stack<char> *S2 = new stack<char>();
    i = sizeOfString(exp);
    for (int j = i - 1; j > -1; j--)
    {
        if (exp[j] == ')')
        {
            S2->push(')');
        }
        if (exp[j] == '(')
        {
            S2->pop();
        }
    }

    return S->isEmpty() && S2->isEmpty();
}


//infic to postfix conversion :: NORMAL
int presidence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
}

void convert(char *exp)
{
    int size = sizeOfString(exp);
    char *postfix = new char[size];
    stack<char> *S = new stack<char>();
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if ((exp[i] >= 65 && exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122))
        {
            postfix[j] = exp[i];
            j++;
        }
        else
        {
            if (S->isEmpty())
            {
                S->push(exp[i]);
            }
            else
            {
                while (presidence(exp[i]) <= presidence(S->stackTop()))
                {
                    postfix[j] = S->pop();
                    j++;
                    if (S->isEmpty())
                    {
                        break;
                    }
                }
                S->push(exp[i]);
            }
        }
    }
    while (!(S->isEmpty()))
    {
        postfix[j] = S->pop();
        j++;
    }
    for (int i = 0; i < size; i++)
    {
        exp[i] = postfix[i];
    }
}

// infix to postfix conversion :: general
int outStackPresidence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    if (c == '*' || c == '/')
    {
        return 3;
    }
    if(c=='^'){
        return 6;
    }
    if(c=='('){
        return 7;
    }
    if(c==')'){
        return 0;
    }
    return -1;
}

int inStackPresidence(char c){
    if (c == '+' || c == '-')
    {
        return 2;
    }
    if (c == '*' || c == '/')
    {
        return 4;
    }
    if(c=='^'){
        return 5;
    }
    if(c=='('){
        return 0;
    }
    return -1;
}

void convertPostfix(char *exp)
{
    int size = sizeOfString(exp);
    int tempSize = size;
    char *postfix = new char[size];
    stack<char> *S = new stack<char>();
    int j = 0; //maintaining number of chars in the postfix
    for (int i = 0; i < size; i++)
    {
        // variables
        if ((exp[i] >= 65 && exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122))
        {
            postfix[j] = exp[i];
            j++;
        }

        // case when the parenthesis close and we dump out all the inside matters out
        else if(exp[i]==')'){
            tempSize -= 2; // () are 2 characters too
            while(S->stackTop() != '('){
                postfix[j]=S->pop();
                j++;
            }
            S->pop(); //pops out the starting parenthesis but doesnt add it to postfix
        }

        else //it is some operation
        {
            if (S->isEmpty()) // if the stack is just empty no checks req., just dunk it in
            {
                S->push(exp[i]);
            }
            else // stack isnt empty so we need to take care
            {
                while (outStackPresidence(exp[i]) <= inStackPresidence(S->stackTop())) //presidence of the expression we r adding (outside the stack rn) <= presidence of expression on stack top
                {
                    postfix[j] = S->pop(); // we pop then acc to ruless and put it in postfix
                    j++;
                    if (S->isEmpty()) // if while doing this thing, it gets empty, just break the while
                    {
                        break;
                    }
                }
                S->push(exp[i]); // now push the expression[i]
            }
        }
    }

    // now the expression has ended
    while (!(S->isEmpty())) // if the stack isnt empty still
    {
        postfix[j] = S->pop(); // we pop out and fit
        j++;
    }
    for (int i = 0; i < tempSize; i++) //tempSize is the size of exp removinf all the ()
    {
        exp[i] = postfix[i];
    }
    exp[tempSize]='\0';
}

int main()
{
    cout << "Welcome!" << endl;
    while (1)
    {
        cout << "Would you like to create a new stack? If yes then enter 1 else enter 0" << endl;
        int feedback1;
        cin >> feedback1;
        if (feedback1 == 0)
        {
            break;
        }
        stack<int> *S = new stack<int>();
        while (1)
        {
            cout << "The operations available are:" << endl;
            cout << "1. Push element" << endl
                 << "2. Pop element" << endl
                 << "3. Peek an element at any index" << endl
                 << "4. Get value of the top element of stack" << endl
                 << "5. Check if stack is empty ?" << endl
                 << "6. Check if stack is full" << endl
                 << "7. Get the current stack size" << endl
                 << "8. Exit" << endl;
            cout << "ENTER ANY ONE OPTION" << endl;
            int feedback2;
            cin >> feedback2;
            if (feedback2 == 8)
            {
                break;
            }
            switch (feedback2)
            {
            case 1:
                cout << "Enter the element you wanna push" << endl;
                int element;
                cin >> element;
                S->push(element);
                break;

            case 2:
                cout << S->pop() << endl;
                break;

            case 3:
                cout << "Enter the index you wanna peak: " << endl;
                int index;
                cin >> index;
                cout << S->peek(index) << endl;
                break;

            case 4:
                cout << S->stackTop() << endl;
                break;

            case 5:
                cout << S->isEmpty() << endl;
                break;

            case 6:
                cout << S->isFull() << endl;
                break;

            case 7:
                cout << S->stackSize() << endl;
                break;

            default:
                cout << "INVALID ENTRY" << endl;
                break;
            }
        }
    }
    char expression[] = "((a+b)*(b+c))";
    cout << parenthesisMatch(expression) << endl;
    char exp[] = "((a+b)*c)-d^e^f";
    convertPostfix(exp);
    cout << exp;
    return 0;
}
