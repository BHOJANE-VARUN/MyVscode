#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
bool mono(int k,vector<pair<int,int>> &arr)
{
    int left =-k,right =k;
    for(auto i:arr)
    {
        if(k==4)
        {
            cout<<left<<" "<<right<<endl;
        }
        if(right<i.second and left<i.first)
        {
            if(right+k>=i.first)
            {
                left = i.first,right = min(i.second,right+k);
            }
            else return false;
        }
        else if(left>i.second)
        {
            if(left-k<=i.second)
            {
                left = max(right-k,i.first),right = i.second;
            }
            else return false;
        }
        else{
            right = min(i.second,right+k);
            left = max(right-k,i.first);
        }
    }
    return true;
}
signed main()
{
test
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    int high =0;
    for(int i =0;i<n;i++)
    {
      cin>>arr[i].first>>arr[i].second;
      high = max(high,max(arr[i].first,arr[i].second));
    }
    int low =0;
    int mid;
    int ans =0;
    while(low<=high)
    {
        mid = low + (high-low)/2;
       // cout<<mono(mid,arr)<<" "<<mid<<" "<<low<<" "<<high<<endl;
        if(mono(mid,arr))
        {
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}