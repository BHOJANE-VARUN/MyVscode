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
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    unordered_map<int,int> mp;
    for(int i =0;i<n;i++)
    {
        mp[arr[i]] = i+1;
    }
   // for(auto i:mp) cout<<i.first<<" "<<i.second<<endl;
    int ele =-1;
    for(int i =0;i<n;i++)
    {
        cout<<mp[ele]<<" ";
        int temp = mp[ele];
        ele = temp;
    }  
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}