#include <bits/stdc++.h>
using namespace std;         
#include <bits/stdc++.h> 
vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    vector<int> ans;
    for(int col=0;col<n;col++)
    {
        for(int row =0;row<n;row++)
        {
            ans.push_back(mat[row][col]);
        }

    }
     sort(ans.begin(),ans.end());
     return ans;
}