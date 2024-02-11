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
   string str;
   cin>>str;
   int i =0;
   while(str[i]!='B' and i<str.length() and str[i]=='A')
   {
    i++;
   }
   while(str[i]!='C' and i<str.length() and str[i]=='B')
   {
    i++;
   }
   while(str[i]=='C' and i<str.length() and str[i]=='C')
   {
    i++;
   }
   if(i==str.length()) cout<<Y<<endl;
   else cout<<N<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}