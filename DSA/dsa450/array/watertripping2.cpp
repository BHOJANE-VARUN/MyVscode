#include <bits/stdc++.h> 
using namespace std;
long long getTrappedWater(long long* arr, int n){
    vector<pair<int,int>>ans(n,{-1,-1});
    int highl =0,highr=0;
    for(int i =0;i<n;i++)
    {   
        if (arr[i]>=highl)
        {
            highl=arr[i];
            ans[i].first = 0;
        }
        else
        {
            ans[i].first = highl;
        }
        if (arr[n-1-i]>=highr)
        {
            highr=arr[n-1-i];
            ans[n-1-i].second = 0;
        }
        else
        {
            ans[n-1-i].second = highr;
        }
        
        
    }
    long long water =0;
    int j =0;
    for(auto i:ans)
    {  
         if(i.first!=0 && i.second!=0){
        water+=(min(i.first,i.second))-arr[j];
        }
        j++;
    }
    return water;
}
int main()
{
    long long test[] = {8 ,1, 8 ,2 ,4 };
    int n = 5;
    long long as = getTrappedWater(test,n);
    cout<<as;
}