#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int> & arr,int m,long long mid)
{   long long sum=0;
    for(auto i:arr)
    {   
        if(i<mid)continue;
        else sum+=i-mid;
    }
    if(sum>=m)return true;
    else return false;
}
int getMaxMarker(vector<int> &arr, int n, int m)
{
    int low = 0,high = accumulate(arr.begin(),arr.end(),0);
    long long ans=-1;
    while (high>=low)
    {   long long mid = (high+low)/2;
        if(check(arr,m,mid)) ans = mid,low= mid+1;
        else high = mid-1;
    }
    return ans;
    
}
int main()
{
    vector<int> test = {10,30,40,10};
    int m = 30,n = test.size();
    cout<<getMaxMarker(test,n,m);
}