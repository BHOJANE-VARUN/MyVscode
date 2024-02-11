#include<bits/stdc++.h>
using namespace std;
long long sameDigits(long long n) {
    // Write your code here.
    if(n==0) return 0;
    int size =0;
    int temp =n;
    while(n)
    {
        n = n/10;
        size++;
    }
    int mini =100000;
    int ele =0;
    for(int i =1;i<10;i++)
    {   int j=0;
        long long num =0;
        while(j<size)
        {
            num = num*10;
            num = num+i;
            j++;
        }
        if(abs(num-temp)<mini)
        {
            mini = abs(num-temp);
            ele = num;
        }
    }
    return ele;
}
int main()
{
    cout<<sameDigits(49);
}