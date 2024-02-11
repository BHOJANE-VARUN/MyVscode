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
    int n,m;
    cin>>n>>m;
    multiset<int> arr;
    for(int i =0;i<n;i++)
    {   int temp;
    cin>>temp;
      arr.insert(temp);
    }
    for(int i =0;i<m;i++)
    {
        int temp;
        cin>>temp;
        auto it = arr.upper_bound(temp);
        if((it)==arr.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            it--;
            cout<<(*it)<<endl;
            arr.erase(it);
        }
    }
//dusro ka code copy karne se ghar nahi chalta bhai
}