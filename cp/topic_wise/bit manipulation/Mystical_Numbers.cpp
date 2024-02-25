#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int bit(int n){
  int cnt=0;
    while(n){
        n/=2; cnt++;
    }
    return cnt;
}
signed main()
{
test
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<vector<int>> prefix;
    // for(int i =0;i<32;i++)
    // {
    //     vector<int> cur(n+1,0);
    //     for(int j =0;j<n;j++)
    //     {
    //         if(((1<<i)&arr[j])>0)
    //         {
    //             cur[j+1] = cur[j]+1;
    //         }
    //         else cur[j+1] = cur[j];
    //     }
    //     prefix.push_back(cur);
    // }
    vector<vector<int>>v;
   
    vector<int>bits(32,0);
     v.push_back(bits);
    for(int i=0;i<n;i++){
        int leftpos= bit(arr[i]);
        bits[leftpos]++;
        v.push_back(bits);
    }
    for(auto i:v)
    {
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int l,r,x;
    //     cin>>l>>r>>x;
    //     int msb =0;
    //     for(int i =31;i>=0;i--)
    //     {
    //         if(((1<<i)&x)>0)
    //         {
    //           msb =i;
    //           break;
    //         }
    //     } 
    //     int ele = r-l+1;
    //     int setbits = prefix[msb][r]-prefix[msb][l-1];
    //     cout<<(ele-setbits)<<endl;
    // }
}
//dusro ka code copy karne se khar nahi chalta bhai
}