#include<iostream>
using namespace std;
class Complex{
    public:
    int real,img;
    Complex(){
        real =0,img = 0;
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
    Complex operator*(Complex& other){
        Complex result;
        result.real = (real * other.real) - (img * other.img);
        result.img = (real * other.img) + (img * other.real);
        return result;
    }
    friend ostream& operator<<(ostream&out,Complex& a);
    friend istream& operator>>(istream&in,Complex& a);
};
ostream& operator<<(ostream&out,Complex& a)
{
    out<<a.real<<" + "<<a.img<<"i"<<endl;
    return out;
}
istream& operator>>(istream&in,Complex& a)
{
    cout<<"Enter the real value:";
    in>>a.real;
    cout<<"Enter the imaginary value:";
    in>>a.img;
    return in;
}
int main()
{
    Complex obj1,obj2;
    cin>>obj1;
    cin>>obj2;
    cout<<"multiplication:"<<endl;
    Complex result = obj1*obj2;
    cout<<result;
    cout<<"Addition:"<<endl;
    Complex addition = obj1+obj2;
    cout<<addition;
}