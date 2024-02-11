#include<iostream>
using namespace std;
class number{
    public:
    int num;
    number()
    {
        cout<<"Enter the number:";
        cin>>num;
    }
};
class square:public number{
    public:
    void squarenum()
    {
        cout<<"square of number is :"<<num*num<<endl;
    }
};
class cube:public number{
    public:
    void cubenum()
    {
        cout<<"cube of number is :"<<num*num<<endl;
    }
};
int main()
{
    square obj1;
    cube obj2;
    obj1.squarenum();
    obj2.cubenum();
}