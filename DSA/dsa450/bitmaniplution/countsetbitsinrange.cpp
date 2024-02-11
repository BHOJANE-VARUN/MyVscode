#include <bits/stdc++.h> 
using namespace std;
int countBits(int N) {

    int count = 0;
    int r;

    while (N > 0) {

        r = N % 2;
        
        if (r == 1)
        {
            count++;
        }

        N = N / 2;
    }

    return count;
}
int countSetBits(int n) {
    // Write your code here
    int temp= 1;
    int power = 0;
    while(n>temp)
    {
        int iner = (temp<<1);
        if(iner<n) temp = iner;
        else break;
        power++;
    }
    int ans= (temp*power)/2 + 1;
    for(int i =temp+1;i<=n;i++)
    {
      ans += countBits(i);
    }
    return ans;
}
int main()
{
    cout<<countSetBits(5);
}