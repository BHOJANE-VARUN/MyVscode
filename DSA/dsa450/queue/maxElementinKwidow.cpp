#include <bits/stdc++.h> 
using namespace std;
vector<int> maxOfSubarray(vector<int> nums, int n, int k) 
{   if(k==1)
        return nums;
	deque<int> q;
    vector<int> ans;
    for(int i =0;i<k;i++)
    {
        while(!q.empty() && nums[q.back()]<=nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    for(int i =k;i<nums.size();i++)
    {
        while (q.front()<=i-k)
        {
            q.pop_front();
        }
        
        while(!q.empty() && nums[q.back()]<=nums[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(nums[q.front()]);
    }
    
    return ans;
}
int main()
{//7 1

    vector<int> vec = {6 ,13, 3 ,11, 7, 6 ,15 };
    vector<int> ans = maxOfSubarray(vec,vec.size(),1);
    for(auto i:ans)
    {
        cout<<i<<endl;
    }
}
