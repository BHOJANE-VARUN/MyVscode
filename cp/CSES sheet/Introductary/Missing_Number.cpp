#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
signed main()
{

{
    int n;
    cin>>n;
    int temp;
    int tempxor =0;
    for(int i =0;i<n-1;i++)
    {
      cin>>temp;
       tempxor = tempxor^temp;
    }
    int actual =0;
    for(int i =1;i<=n;i++) actual = actual^i;
    cout<<(actual^tempxor)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}