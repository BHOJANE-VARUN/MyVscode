#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void radixsort(vector<int> &arr,int k)
{
    vector<int> count(10,0);
    for(auto i:arr)
    {
        count[(i/k)%10]++;
    }
    //for(auto i:count) cout<<i<<" ";cout<<endl;
    for(int i =1;i<10;i++)
    {
        count[i] += count[i-1];
    }
   // for(auto i:count) cout<<i<<" ";cout<<endl;
    vector<int> ans(arr.size());
    for(int i =arr.size()-1;i>=0;i--)
    {
        ans[count[((arr[i]/k)%10)]-1] = arr[i];
        count[(arr[i]/k)%10]--;
    }
    arr = ans;
}
signed main()
{
    vector<int> arr = {4,31,36,756,37,84,73};
    int maxi = *max_element(arr.begin(),arr.end());
    int k =1;
    while (maxi)
    {
         radixsort(arr,k);
        for(auto i:arr) cout<<i<<" ";
        cout<<endl;
        k = k*10;maxi = maxi/10;
    }
    
   
//dusro ka code copy karne se ghar nahi chalta bhai
}