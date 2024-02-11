#include <bits/stdc++.h>
using namespace std;
int findMaxValue(vector<vector<int>> &mat, int n)
{
    int ans = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int row = i; row >= 0; row--)
        {
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < i; c++)
                {
                    ans = max(ans,mat[row][i] - mat[r][c]);
                }
            }
        for (int col = i ; col >= 0; col--)
            {
            for (int r = 0; r < col; r++)
            {
                for (int c = 0; c < i; c++)
                {
                    ans = max(ans,mat[i][col]-mat[r][c]);
                }
            }
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> test = {{-1, 5 ,-3},{-14 ,-5 ,-2},{-7, 8 ,-9}};
    int n = test.size();
    int ans = findMaxValue(test, n);
    cout << ans;
}