#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputarrint(int *arr,int n)
// {   int temp;
//     for(int i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int power(int x,int y, int p) 
{ 
    int res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
int32_t main()
{
test
{
    int n;
    unsigned int k;
    cin>>n>>k;
    unsigned int num = n-k;
    string str;
    cin>>str;
    int ans;
    if(n==k){ cout<<2<<endl;continue;}
    if(k%2!=0)
     ans = power(2,n-1,MOD);
    else ans = power(2,n-2,MOD);
    ans = (ans*(2*(1ll )))%MOD;
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}