#include <bits/stdc++.h> 
vector<int> rearrange(vector<int>& num)
{
    //  Write you code here
    //  Return a valid rearrangement
    //  Return {-2147483648}, if there is no valid rearrangement
    
    
    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>mp;
    for (auto it: num)
    {
        mp[it]++;
    }
    for (auto it: mp)
    {
        pq.push({it.second,it.first});
    }
    vector<int>ans;
    while(!pq.empty())
    {
        auto temp=pq.top();
        pq.pop();
        int freq=temp.first;
        int val=temp.second;
        ans.push_back(val);
        freq--;
        if (!pq.empty())
        {
            auto temp2=pq.top();
            pq.pop();
            int freq2=temp2.first;
            int val2=temp2.second;
            ans.push_back(val2);
            freq2--;
            if (freq2) pq.push({freq2,val2});
        }
        else {
            if (freq>0) return {-2147483648};
        }
        if (freq>0) pq.push({freq,val});
    }
    return ans;

}