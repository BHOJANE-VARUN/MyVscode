#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
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
    int ans =0;
    for(int i =31;i>=0;i--)
    {   
        vector<int> setbits;
        for(int k =0;k<n;k++)
        {
            if((arr[k]&(1<<i))>0)
            {
                setbits.push_back(k);
            }
        }
        int siz = setbits.size();
        if(setbits.size()>1)
        {
            ans += (siz*(siz-1))/2;
        }
        for(int i =0;i<setbits.size();i++)
        {
           // cout<<arr[setbits[i]]<<" ";
            arr[setbits[i]] = 0;
        }
       // cout<<endl;
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}