#include<iostream>
using namespace std;
long long power(int base,int rase)
{   if(rase==0)
    return 1;
    if(rase==1)
    return base;

    if(rase%2==0)
    {
        long long ans = power(base,rase/2);
        return ans*ans;
    }
    else{
        long long  ans = power(base,rase/2);
        return base*ans*ans;
    }
}
int main()
{
    cout<<power(2,55);
}