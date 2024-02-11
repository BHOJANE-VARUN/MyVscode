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
    int *arr = new int[n];
    inputarrint(arr,n);
    if(n<=2)
    {
        cout<<-1<<endl;
        continue;
    }
    
    int even =2 ,odd =5;
    for(int i =0;i<n;i++)
    {
        if(arr[i]==1)
        {
            cout<<3<<" ";
        }
        else if(arr[i]==3)
        {
            cout<<1<<" ";
        }
        else if(arr[i]%2==0)
        {
            cout<<even<<" ";
            even += 2;
        }
        else{
            cout<<odd<<" ";
            odd += 2;
        }
    }
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}