#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

    //Write your countBits function here
void printbianry(int num)
{
    for(int i =3;i>=0;i--)
    {
        if((num & (1<<i))!=0)
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<"\n";
}
int countBits(int n)
{   int count =0;
    for(int i =0;i<32;i++)
    {
        if((n & (1<<i))!=0) count++;
    }
    return count;
}

int main() {
    int n = 8;
    //n*power/2+1
    int ans =0;
    for(int i =1;i<=n;i++)
    {   ans += countBits(i);
        printbianry(i);
    }
    cout<<ans;
}