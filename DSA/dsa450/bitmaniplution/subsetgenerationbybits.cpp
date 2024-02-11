#include <bits/stdc++.h> 
using namespace std;
set<vector<int>> Subsets(int n, vector<int> &arr)
{   set<vector<int>> ans;
    int count = (1<<n);
    for (int i = 0; i < count; i++)
    {   vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if((i & (1<<j))!=0)
            {
                temp.push_back(arr[j]);
            }
        }
        ans.insert(temp);
    }
    return ans;
}
int main()
{
    vector<int> vec = {1,1,3};
    set<vector<int>> ans = Subsets(vec.size(),vec);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}