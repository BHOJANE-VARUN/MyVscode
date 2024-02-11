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
test
{
    int n,m;
    cin>>n>>m;
    int *arr = new int[m];
    inputarrint(arr,m);
    if(m==1)
    {
        cout<<0<<endl;
        continue;
    }
    sort(arr,arr+m);
    //n-1 opeartions, n chains
    int i =1;
    int ele = arr[0];
    while(i<m and ele<(m-i-1))
    {
        
        ele += arr[i];
        i++;
       
    }
    if(ele==(m-i-1))
    {
        cout<<(m-i-1)<<endl;
    }
    else cout<<(m-i)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}