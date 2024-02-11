#include <bits/stdc++.h> 
using namespace std;
int floorSqrt(int n)
{   if(n<2)return n;
    long long low =1,high = n;
    long long m;
    while(high-low>1)
    {   m = (high+low)/2;
        if(m*m>n)high = m;
        else low = m;
    }
    return low;
}

int main()
{
    cout<<floorSqrt(28);
}