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
bool valid(int i, int j, int n, int m)
{
    if (i >= 0 and i < n and j >= 0 and j < m)
        return true;
    else
        return false;
}
void visitor(vector<vector<int>> &arr, int row, int col, vector<int> &dir)
{
    int n = arr.size(), m = arr[0].size();
    arr[row][col] = 0;

    for (int i = 1; i < dir.size(); i++)
    {
        int r = row + dir[i - 1];
        int c = col + dir[i];
        if (valid(r, c, n, m) and arr[r][c])
        {
            visitor(arr, r, c, dir);
        }
    }
}
signed main()
{

    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        vector<int> dir = {0, 1, 0, -1, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char a;
                cin >> a;
                if (a == '.')
                    arr[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j])
                {
                    ans++;
                    visitor(arr,i, j, dir);
                }
            }
        }
        cout << ans << endl;
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}