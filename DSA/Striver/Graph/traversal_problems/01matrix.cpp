#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) q.emplace(r, c);
                else mat[r][c] = -1; // Marked as not processed yet!

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};
//dynamic programming approch
class Solution { // 48 ms, faster than 99.64%
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n; // The distance of cells is up to (M+N)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                int top = INF, left = INF;
                if (r - 1 >= 0) top = mat[r - 1][c];
                if (c - 1 >= 0) left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = INF, right = INF;
                if (r + 1 < m) bottom = mat[r + 1][c];
                if (c + 1 < n) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}
