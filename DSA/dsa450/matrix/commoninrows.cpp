#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    unordered_map<int, int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
                if (i==0)
                {
                    temp[mat[i][j]] = i+1;
                }
                else
                {
                    if (temp[mat[i][j]] == i)
                    {
                        temp[mat[i][j]] = i+1;
                    }
                    
                }
                
                
                
            
            
        }
    }
    for (auto i : temp)
    {   
        if (i.second == n)
        {   
            ans.push_back(i.first);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> test = {{1, 2, 3}, {2, 2, 3}, {2, 3, 1}};
    vector<int> ans = findCommonElements(test);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
