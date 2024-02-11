#include<bits/stdc++.h>
using namespace std;
void show(int num)
{
    for(int i =64;i>=0;i--)
    {
        if(num&(1<<i)) cout<<1;
        else cout<<0;
    }
    cout<<endl;
}
long ResetAllBitsInRange(long num, int left, int right) {

int temp =1;
    for(int i =right;i<=left;i++)
    {
        num = (num^(temp<<i));
        show(num);
    }
    return num;
}

signed main()
{
    //52394284
//55
//9
    cout<<ResetAllBitsInRange(52394284,55,9)<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}