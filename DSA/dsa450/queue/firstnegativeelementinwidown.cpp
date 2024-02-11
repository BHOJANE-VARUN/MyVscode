#include <bits/stdc++.h> 
using namespace std;
vector<int> firstNegative(vector<int> arr, int n, int k) {
	// Write your code here.
	vector<int> ans;
    deque<int> q;
    for(int i =0;i<k;i++)
    {
        if(arr[i]<0)
        {
            q.push_back(i);
        }
    }
    if(q.size()>0)
    {
        ans.push_back(arr[q.front()]);
    }
    else{
        ans.push_back(0);
    }
    for(int i =k;i<arr.size();i++)
    {   
        if(!q.empty() && (i-q.front())>=k)
        {
            q.pop_front();
        }
        if(arr[i]<0)
        {
            q.push_back(i);
        }
        if(q.size()>0)
        {
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    vector<int> vec = {-1, 2 ,6 ,-5 ,-4};
    vector<int> ans = firstNegative(vec,vec.size(),2);
    for(auto i:ans) cout<<i<<endl;
}