#include <bits/stdc++.h> 
using namespace std;
vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	unordered_map<int,int> temp;
    vector<int> ans;
    int tar = n/k;
    for(auto i:arr)
    {      
        temp[i]++;    
    }
    for(auto i:temp)
    {
        if(i.second>=tar)
        {
           ans.push_back(i.first); 
        }
    }
    return ans;
}
int main()
{   vector<int> vec = {1,1,1,4,3,5,6,6,6};
    int n = vec.size();
    int k = 3;
    countTheNumber(vec,n,k);
    return 0;
}