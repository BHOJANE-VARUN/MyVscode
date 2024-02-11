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
    vector<int> arr;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        int index = upper_bound(arr.begin(),arr.end(),a)-arr.begin();
        if(index<arr.size())
        {
            arr[index] = a;
        }
        else{
            arr.push_back(a);
        }
        
    }
    cout<<arr.size()<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}