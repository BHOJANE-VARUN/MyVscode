#include<iostream>
using namespace std;
class Complex{
    public:
    int real,img;
    Complex(){
        cout<<"imginary part:";
        cin>>img;
        cout<<"real part:";
        cin>>real;
    }
    Complex(int a,int b)
    {
        real = a;
        img = b;
    }
    Complex operator +(Complex& a)
    {
        int curreal = a.real + real;
        int curimg = a.img + img;
        Complex temp(curreal,curimg);
        return temp;
    }
    friend Complex operator-(Complex&a,Complex&b);
};
Complex operator-(Complex&a,Complex&b)
{
    int curreal = a.real - b.real;
    int curimg = a.img - b.img;
    Complex temp(curreal,curimg);
    return temp;
}
int main()
{
    Complex obj1,obj2;
    Complex obj = obj1+obj2;
    cout<<"After addition:"<<endl;
    cout<<obj.real<<" + "<<obj.img<<"i"<<endl;
    obj = obj1-obj2;
    cout<<"After Subtraction:"<<endl;
    cout<<obj.real<<" + "<<obj.img<<"i"<<endl;
}