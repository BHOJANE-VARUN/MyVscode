#include <bits/stdc++.h> 
using namespace std;
int countCustomers(vector<int> &arr, int k)
{
   int count =0;
   int ans =0;
   unordered_set<int> map;
    for(int i=0;i<arr.size();i++)
    {   auto it = map.find(arr[i]);
        if(count<k && it==map.end())
        {   
            map.insert(arr[i]);
        }
        else if(it!=map.end()){
            map.erase(it);
        }
        else{
            ans++;
        }
    }
    return ans;
}
