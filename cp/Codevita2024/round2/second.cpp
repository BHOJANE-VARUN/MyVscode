
#include <bits/stdc++.h>
// #define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
int timeee[101][101];
int grid[101][101];
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    if (i < 0 or i > n - 1 or j < 0 or j > m - 1)
    {
        return false;
    }
    else
        return true;
}

// void solve(priority_queue<pair<int,pair<int,int>>>&pq, int health, int ti, pair<int, int> &ans, int &n, int &m, pair<int, int> &end)
// {
//     if(pq.empty()) return;
//     int i = pq.second.first,j = pq.second.second;
//     if(ans.first<ti)
//     {
//         return;
//     }

//     if (i == end.first and j == end.second)
//     {
//         if (ans.first == INT_MAX or ans.first > ti)
//         {
//             ans = { ti,
//                     health };
//         }
//         else if (ans.first == ti and health > ans.second)
//         {
//             ans = {ti, health};
//         }
//         return;
//     }
//     vector<int> row = {1, 0, -1, 0};
//     vector<int> col = {0, 1, 0, -1};

//     for (int x = 0; x < 4; x++)
//     {
//         if (isValid(i + row[x], j+col[x], n, m) and grid[i + row[x]][j+col[x]] != -1 and health >= grid[i + row[x]][j+col[x]] + 1)
//         {
//             int temp = grid[i + row[x]][j+col[x]];
//             grid[i + row[x]][j+col[x]] = -1;
//             solve(i + row[x], j+col[x], health - temp - 1, ti + timeee[i+row[x]][j+col[x]], ans, n, m, end);
//             grid[i + row[x]][j+col[x]] = temp;
//         }
//     }
// };
struct comp
{
    bool operator()(const pair<int, pair<int, pair<int, int>>> &a,
                    const pair<int, pair<int, pair<int, int>>> &b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        return a.second.first < b.second.first;
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};

    // vector<vector<int>> grid(n, vector<int>(m));
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string temp;
            cin >> temp;
            if (temp[0] == 'S')
            {
                start = {i, j};
                grid[i][j] = 0;
            }
            else if (temp[0] == 'D')
            {
                end = {i, j};
            }
            else
                grid[i][j] = stoi(temp);
        }
    }
    // vector<vector<int>> timeee(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeee[i][j];
        }
    }
    int hea;
    cin >> hea;
    pair<int, int> ans = {INT_MAX, INT_MAX};
    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, comp> pq;
    pq.push({0, {hea, start}});
    // solve(start.first,start.second,hea,0,ans,n,m,end);
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    while (!pq.empty())
    {
        int ti = pq.top().first, health = pq.top().second.first, i = pq.top().second.second.first, j = pq.top().second.second.second;
        pq.pop();
        if (ans.first < ti)
        {
            continue;
        }

        if (i == end.first and j == end.second)
        {
            // if (ans.first == INT_MAX or ans.first > ti)
            // {
            //     ans = {ti,
            //            health};
            // }
            // else if (ans.first == ti and health > ans.second)
            // {
            //     ans = {ti, health};
            // }
            // continue;
            cout<<ti<<" "<<health<<endl;
            return 0;
        }

        for (int x = 0; x < 4; x++)
        {
            if (isValid(i + row[x], j + col[x], n, m) and visited[i + row[x]][j + col[x]] != true and health >= grid[i + row[x]][j + col[x]] + 1)
            {
               
                visited[i + row[x]][j + col[x]] = true;
               // solve(i + row[x], j + col[x], health - temp - 1, ti + timeee[i + row[x]][j + col[x]], ans, n, m, end);
                pq.push({ti+timeee[i+row[x]][j+col[x]],{health - grid[i + row[x]][j + col[x]] - 1,{i+row[x],j+col[x]}}});
                visited[i + row[x]][j + col[x]] = false;
            }
        }
    }
    //if (ans.first == INT_MAX and ans.second == INT_MAX)
   // {
        cout << "Not Possible" << endl;
    //}
    //else
      //  cout << ans.first << " " << ans.second << endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}