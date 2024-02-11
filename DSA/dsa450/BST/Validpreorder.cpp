#include <bits/stdc++.h> 
using namespace std;
bool solve(vector<int> &arr,int s,int e,int mini,int maxi)
{
    if(e<s)
    {
        return true;
    }
    int mid =-1;
    for(int i =s;i<=e;i++)
    {
        if(arr[i]>=maxi or arr[i]<=mini)
        {
            return false;
        }
        if(i!=s and arr[s]<arr[i] and mid!=-1) mid = i;
    }

    bool lef = solve(arr,s,mid-1,mini,arr[s]-1);
    bool rig = solve(arr,mid,e,arr[s]+1,maxi);
    return (lef and rig);
}
int isPreorderValid(vector<int> &arr) 
{   if(arr.size()<3) return true;
   return  solve(arr,0,arr.size()-1,INT_MIN,INT_MAX);
}
int main()
{
    return 0;
}
