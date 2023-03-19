#include <iostream>
using namespace std;

class term
{
public:
    int coff;
    int power;
    term *next;
    term(int coff, int power)
    {
        this->coff = coff;
        this->power = power;
        next = NULL;
    }
};

class polynomial
{
public:
    term *highestTerm;
    int degree;
    polynomial()
    {
        highestTerm = NULL;
        degree = 0;
    }
    void create()
    {
        cout << "Enter the degree of the polynomial" << endl;
        int deg;
        cin >> deg;
        degree = deg;
        term *temp = highestTerm;
        while (deg > -1)
        {
            cout << "Enter the coff of x^" << deg << endl;
            int val;
            cin >> val;
            term *newTerm = new term(val, deg);
            if (temp == NULL)
            {
                highestTerm = newTerm;
                temp = highestTerm;
            }
            else
            {
                temp->next = newTerm;
                temp = temp->next;
            }
            deg--;
        }
    }
    void display()
    {
        int deg = degree;
        term *temp = highestTerm;
        while (deg--)
        {
            cout << temp->coff << "x^" << temp->power << " + ";
            temp = temp->next;
        }
        cout << temp->coff << endl;
    }
};

polynomial* addPolynomials(polynomial* poly1, polynomial* poly2){
    int deg1 = poly1->degree;
    int deg2 =  poly2->degree;
    polynomial* finalPoly =  new polynomial();
    finalPoly->degree=max(deg1,deg2);

    //balancing the terms
    if(deg1>deg2){
        //changes to be made in polynomial 2
        int i =  deg2+1;
        while(i<=deg1){
            term* newTerm = new term(0,i);
            newTerm->next=poly2->highestTerm;
            poly2->highestTerm=newTerm;
            poly2->degree=i;
            i++;
        }
    }
    else if(deg2>deg1){
        //changes to be made in polynomial 1
        int i = deg1 + 1;
        while(i<=deg2){
            term* newTerm = new term(0,i);
            newTerm->next=poly1->highestTerm;
            poly1->highestTerm=newTerm;
            poly1->degree=i;
            i++;
        }
    }

    //now adding 
    term* t1 = poly1->highestTerm;
    term* t2 = poly2->highestTerm;
    term* temp = finalPoly->highestTerm;
    while(t1!=NULL){
        term* newTerm = new term(t1->coff+t2->coff, t1->power);
        if(temp==NULL){
            temp=newTerm;
            finalPoly->highestTerm=newTerm;
        }
        else{
            temp->next=newTerm;
            temp=newTerm;
        }
        t1=t1->next;
        t2=t2->next;
    } 

    return finalPoly;
}

int main()
{
    polynomial *poly1 = new polynomial();
    poly1->create();
    poly1->display();
    polynomial * poly2 =  new polynomial();
    poly2->create();
    poly2->display();
    addPolynomials(poly1,poly2)->display();
    return 0;
}
