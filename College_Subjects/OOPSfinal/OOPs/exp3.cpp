#include<iostream>
using namespace std;
class shape
{

    
public:
double length,breadth;
    shape();
    void area(){cout<<"i am abtract"<<endl;};
};

shape::shape()
{
    cout<<"Enter a and b :";
    cin>>length>>breadth;
}
class triangle: public shape
{
     public:
     void area()
{
    cout<<0.5*length*breadth<<endl;
}
};

class circle:public shape
{
    public:
    void area()
{
    cout<<3.14*length*length<<endl;
}
};

int main()
{
    triangle obj;
    circle ob;
    shape* ptr = &obj;
    ptr->area();
    ptr = &ob;
    ptr->area();
}

