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
    vector<int> DIR = {0, 1, 0, -1, 0};
    bool valid(int i, int j, int n, int m)
    {
        if (i >= 0 and i < n and j >= 0 and j < m)
            return true;
        else
            return false;
    }

    void visitor(vector<vector<char>> &image, int i, int j)
    {
        int n = image.size(), m = image[0].size();
        image[i][j] = '#';
        for (int k =0;k<4;k++)
        {
            int a = i + DIR[k], b = j + DIR[k+1];
            if (valid(a, b, n, m) and image[a][b] == 'O')
                visitor(image, a, b);
        }
        
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(),m = board[0].size();
        vector<vector<int>> visit(n,vector<int> (m,0));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if((board[i][j]=='O') and (i==0 or i==n-1 or j==0 or j==m-1))
                    visitor(board,i,j);    
            }
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                else if(board[i][j]=='#')
                    board[i][j] = 'O';   
            }
        }
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}