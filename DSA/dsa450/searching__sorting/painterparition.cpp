#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int> &time,int n,int m,long long  mid)
{
    long long localtime = 0;
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
int allocateBooks(vector<int> &time, int n, int m)
{	if(m>n)return -1;
	long long ans = -1;
	long long low = 0,high = accumulate(time.begin(),time.end(),0);
    while(low<=high)
    {
        long long mid = 1ll*((high+low)/2);
        if(check(time,n,m,mid))ans = mid,high = mid-1;
        else low = mid +1;
    }
    return ans;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    return allocateBooks(boards,boards.size(),k);  
}