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
class Solution
{
public:
    bool valid(int i, int j, int n, int m)
    {
        if (i >= 0 and i < n and j >= 0 and j < m)
            return true;
        else
            return false;
    }
    void visitor(vector<vector<int>> &image,int i,int j,int color,vector<vector<int>> &visit)
    {
        int n = image.size(), m = image[0].size();
        vector<pair<int, int>> neighbors = {
            {i - 1, j}, // top
            {i, j + 1}, // right
            {i + 1, j}, // bottom
            {i, j - 1}, // left
        };
        visit[i][j] = 1;
        for (auto ele : neighbors)
        {
            int a = ele.first, b = ele.second;
            if (valid(a, b, n, m) and image[a][b] == image[i][j] and !visit[a][b])
                visitor(image, a, b,color,visit);
        }
        image[i][j] = color;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> visit(image.size(),vector<int>(image[0].size(),0));
        visitor(image,sr,sc,color,visit);
        return image;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}