#include<iostream>
using namespace std;
class shape{
    public:
    double a,b;
    shape(int x,int y)
    {
        a = x;
        b = y;
    }
    virtual void area() =0;
};
class triangle:public shape{
    public:
    triangle(int x,int y):shape(x,y){}
    void area()
    {
        cout<<"Area of triangle:"<<0.5*a*b<<endl;
    }
};
class Rectangle:public shape{
    public:
    Rectangle(int x,int y):shape(x,y){}
    void area()
    {
        cout<<"Area of Rectangle:"<<a*b<<endl;
    }
};
int main()
{
    int x,y;
    cout<<"Enter x and y:";
    cin>>x>>y;
    triangle obj(x,y);
    obj.area();
    Rectangle obj2(x,y);
    obj2.area();
}