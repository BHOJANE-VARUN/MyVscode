#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the number:";
    cin>>num;
    try{
    if(num<0)
    {
        throw(0);
    }
    }
    catch(int i)
    {
        cout<<"zero exception error"<<endl;
    }
}