#include<iostream>
using namespace std;

class term{
    public:
    int coff;
    int exp;
};

class poly{
    public:
    term* array;
    int degree;
    poly(int degree){
        this->degree=degree;
        array = new term[degree+1];
    }
    void set(){
        for (int i = 0; i <= degree; i++)
        {
            cout<<"Enter coff of exponent "<<i<<endl;
            cin>>array[i].coff;
            array[i].exp=i;
        }
    }
    void get(){
        for (int i = degree; i > 0; i--)
        {
            cout<<array[i].coff<<"x^"<<array[i].exp<<" + ";
        }
        cout<<array[0].coff<<endl;
    }

    poly* add(poly* poly2){
        poly* poly3 = new poly(max(poly2->degree,degree));
        for (int i = 0; i <= max(poly2->degree,degree); i++)
        {
            if(i>degree){
                poly3->array[i].exp=i;
                poly3->array[i].coff=poly2->array[i].coff;
            }
            else if(i>poly2->degree){
                poly3->array[i].exp=i;
                poly3->array[i].coff=array[i].coff;
            }
            else{
                poly3->array[i].exp=i;
                poly3->array[i].coff=array[i].coff+poly2->array[i].coff;
            }
        }
        return poly3;
    }
};

int main(){
    int n1;
    cout<<"Enter degree of polynomial 1: "<<endl;
    cin>>n1;
    poly* poly1 = new poly(n1);
    poly1->set();
    poly1->get();
    int n2;
    cout<<"Enter degree of polynomial 2: "<<endl;
    cin>>n2;
    poly* poly2 = new poly(n2);
    poly2->set();
    poly2->get();
    poly* poly3 = poly2->add(poly1);
    poly3->get();
    return 0;
}
