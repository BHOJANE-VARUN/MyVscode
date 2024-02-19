#include<iostream>
using namespace std;
class complex{
    private:
    int real,img;
    public:
    complex(int a,int b)
    {
        real = a;
        img = b;
    }
    complex()
    {
        cout<<"enter the real part:";
        cin>>real;
        cout<<"enter the img part:";
        cin>>img;
    }
    complex operator+ (complex &a)
    {
       int first =  real + a.real;
       int second =  img + a.img;
       return complex(first,second);
    }
    complex operator* (complex &a)
    {
        int first = (real*a.real)-(img*a.img);
        int second = (real*a.img)+(a.real*img);
        return  complex(first,second);
    }
    friend ostream& operator<< (ostream& os,complex& var);
    friend istream& operator>> (istream& in,complex& var);
};
ostream& operator<< (ostream& os,complex& var)
{
    os<<"the number is "<<var.real<<" +"<<" ("<<var.img<<")i"<<endl;
    return os;
}
istream& operator>> (istream& in,complex& var)
{
    cout<<"Enter the real part:";
    in >> var.real;
    cout<<"Enter the img part:";
    in >> var.img;
    return in;
}
int main()
{
    // complex a(2,3);
    // complex b(4,5);
    // a = a + b;
    // b = a*b;
    // cout<<a<<endl;
    // cout<<b<<endl;
    complex a(0,0);
    cin>>a;
    cout<<a;
}