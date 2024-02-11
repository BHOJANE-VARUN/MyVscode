#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threesum(vector<int> &temp, int n, int t)
{   set<vector<int>> ans;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i + 1; j < n-1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {   vector<int> tar;
                if ((temp[i] + temp[j] + temp[k]) == t)
                {
                    tar.push_back(temp[i]);
                    tar.push_back(temp[j]);
                    tar.push_back(temp[k]);
                    ans.insert(tar);
                    
                }
            }
        }
    }
    vector<vector<int>> varun;
    for(auto &i:ans)
    {   
        varun.push_back(i);
    }
    return varun;
}
int main()
{
    int k = 6;
    int n = 6;
    vector<int> vec = {1 ,2 ,3 ,1 ,2, 3};
    vector<vector<int>> ans = threesum(vec, n, k);
    for (auto i : ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}