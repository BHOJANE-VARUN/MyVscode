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
    int *arr = new int[n];
    int sum1 =0,sum2 =0;
    for(int i =0;i<n;i++)
    {
      int temp;
      cin>>temp;
      sum1+= temp;
      cin>>temp;
      sum2+= temp;
    }
    if(sum1>sum2)
    {
        cout<<"Takahashi"<<endl;
    }
    else if(sum1==sum2) cout<<"Draw"<<endl;
    else cout<<"Aoki"<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}