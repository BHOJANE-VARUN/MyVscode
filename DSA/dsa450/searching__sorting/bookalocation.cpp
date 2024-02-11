#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int> &time,int n,int m,int mid)
{
    int localtime = 0;
    int count = 1;
    for(auto i:time)
    {
        if((localtime+i)<=mid)localtime+=i;
        else{
            if(count<m)count++;
            else return false;
            if(i>mid)return false;
            localtime = i;
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	long long ans = -1;
	long long low = 0,high = accumulate(time.begin(),time.end(),0);
    while(low<=high)
    {
        long long mid = 1ll*((high+low)/2);
        if(check(time,n,m,mid))ans = mid,high = mid-1;
        else low = mid +1;
    }
    return ans;
}
int main()
{
    vector<int> vec = {1,2,2,3,1};
    int n = vec.size();
    int m = 3;
    cout<<ayushGivesNinjatest(n,m,vec);
}