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
   string s,t;
   cin>>s>>t;
   int a =0,b=0;
   int maxa =-1,maxb=-1;
   for(int i =0;i<n;i++)
   {
        if(s[i]!=t[i])
        {
            if(s[i]=='A') b++,maxb=i;
            else a++,maxa=i;
        }
   }
   if(a==b and maxa<maxb)
   {
        cout<<a<<endl;
   }
   else cout<<-1<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}