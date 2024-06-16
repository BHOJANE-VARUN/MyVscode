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
// class Solution
// {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         queue<pair<int, pair<int, int>>> q;
//         vector<vector<int>> visit(n, vector<int>(n, -1));
//         if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1) return -1;
//         if(n==1)
//             return 1;
//         q.push({1,{0, 0}});
//         q.push({1,{n-1,n-1}});
//         while (!q.empty())
//         {
//             int i = q.front().second.first, j = q.front().second.second;
//             int cost = q.front().first;
//             q.pop();
//             cout<<cost<<" "<<i<<" "<<j<<endl;
//             if(i==n-1 and j==n-1 and cost!=1)
//             {
//                 cout<<cost<<endl;
//                 return cost;
//             }

//           //  visit[i][j] = cost;
//             vector<int> rowDir = {-1, -1, -1, 0, 0, 1, 1, 1};
//             vector<int> colDir = {-1, 0, 1, -1, 1, -1, 0, 1};

//             int rows = grid.size();
//             int cols = grid[0].size();

//             for (int k = 0; k < 8; ++k)
//             {
//                 int r = i + rowDir[k];
//                 int c = j + colDir[k];
//                 if (r >= 0 && r < rows && c >= 0 && c < cols and grid[r][c]==0)
//                 {
//                     if (visit[r][c] != -1)
//                         return cost + visit[r][c];
//                     if(r==n-1 and c==n-1)
//                         return cost+1;
//                     visit[r][c] = cost+1;
//                     q.push({cost+1,{r,c}});
//                 }
//             }
//         }
//         return -1;
//     }
// };
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if(grid[0][0]==1 or grid[grid.size()-1][grid.size()-1])
            return -1;
        set<pair<int, int>> s;
        s.insert({0, 0});
        vector<vector<int>> visit(grid.size(), vector<int>(grid.size(), INT_MAX));
        vector<int> rowDir = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> colDir = {-1, 0, 1, -1, 1, -1, 0, 1};
        int rows = grid.size();
        int cols = grid[0].size();
        visit[0][0] = 1;
        while (s.size() != 0)
        {
            int i = (*s.begin()).first, j = (*s.begin()).second;
            s.erase(s.begin());
            for (int k = 0; k < 8; ++k)
            {
                int r = i + rowDir[k];
                int c = j + colDir[k];
                if (r >= 0 && r < rows && c >= 0 && c < cols and grid[r][c] == 0)
                {
                    if(visit[i][j]+1<visit[r][c])
                    {
                        visit[r][c] = visit[i][j] + 1;
                        s.insert({r,c});
                    }
                }
            }
        }
        return visit[grid.size()-1][grid.size()-1]==INT_MAX?-1:visit[grid.size()-1][grid.size()-1];
    }
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}
