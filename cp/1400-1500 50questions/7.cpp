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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int zero =0,one =0;
    for(auto i:str)
    {
        if(i=='1') one++;
        else zero++;
    }
    int ans = min(zero,one);
    if(ans%2==0) cout<<"Ramos"<<endl;
    else cout<<"Zlatan"<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}