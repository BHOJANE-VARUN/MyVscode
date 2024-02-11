#include <bits/stdc++.h>
using namespace std;
void recur(int index, int eleind, int size, vector<vector<int>> &vec, vector<int> &arr, int n, int k, vector<vector<int>> &ans)
{
    if (eleind == n)
        return;
    if (index == size)
        return recur(0, ++eleind, vec.size(), vec, arr, n, k, ans);
    vector<int> temp = vec[index];
    temp.push_back(arr[eleind]);
    int sum = (accumulate(temp.begin(), temp.end(), 0)); 
    if ( sum == k)
    {
        ans.push_back(temp);
    }
    vec.push_back(temp);
    return recur(++index, eleind, size, vec, arr, n, k, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<vector<int>> vec;
    vector<int> temp = {};
    ans.push_back(temp);
    recur(0, 0, ans.size(), ans, arr, n, k, vec);sort(vec.begin(),vec.end());
    return vec;
}
int main()
{
    vector<int> vec = {5, -2, 0, -5, 2};
    vector<vector<int>> ans = findSubsetsThatSumToK(vec, vec.size(), 0);
    
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}