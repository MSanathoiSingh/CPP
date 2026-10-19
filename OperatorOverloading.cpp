#include <iostream>
using namespace std;

class ComplexNo
{
private:
    float real;
    float img;
public:
    ComplexNo()
    {
        real= 0.0;
        img= 0.0;
    }
    ~ComplexNo(){}
    friend ComplexNo operator+(ComplexNo obj, ComplexNo obj1);
    friend ComplexNo operator*(ComplexNo x, ComplexNo x1);
    friend ostream &operator<<(ostream &, ComplexNo &);
    friend istream &operator>>(istream &, ComplexNo &);
};
ComplexNo operator+(ComplexNo x, ComplexNo y)
{
    ComplexNo t;
    t.real= x.real + y.real;
    t.img= x.img + y.img;
    return t;
};
ComplexNo operator*(ComplexNo y, ComplexNo y1)
{
    ComplexNo var;
    var.real = y.real * y1.real - y.img * y1.img;
    var.img = y.real * y1.img + y.img * y1.real;
    return var;
};
ostream &operator<<(ostream &print, ComplexNo &x)
{
    if(x.img>=0){print<<x.real<<"+"<<x.img<<"i\n";}
    else{print<<x.real<<x.img<<"i\n";}
    return print;
};
istream &operator>>(istream &input, ComplexNo &var)
{
    cout<<"Enter Real Part: ";
    input>>var.real;        cout<<endl;
    cout<<"Enter Imaginary Part: ";
    input>>var.img;         cout<<endl;
    return input;
};
int main()
{
    cout<<"Code by MSanathoi"<<endl;
    ComplexNo c, c1, c2;
    int choice;
    cin>>c; //calling of operator overloading function
    cin>>c1;
    do
    {
        cout<<"\n1. Add two complex numbers"<<endl;
        cout<<"2. Multiply two complex numbers"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;        cout<<endl;
        switch(choice)
        {
            case 1: c2= c+c1;
                cout<<"Sum of two numbers is ";
                cout<<c2;
                break;
            case 2: c2= c*c1;
                cout<<"Product of two number is ";
                cout<<c2;
                break;
            case 3: break;
            default: cout<<"Enter valid choice."<<endl;
        }
    } while(choice!=0&&choice!=3);
    return 0;
};

