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
//     vector<int> bfstraversal(int v, vector<vector<int>> &adj,int numcor)
//     {
//         vector<bool> vis(numcor,false);
//         vis[v] = 1;
//         queue<int> q;
//         vector<int> bfs;
//         q.push(v);
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);
//             for (int i =0;i<numcor;i++)
//             {
//                 if(adj[node][i] and adj[i][node])
//                     return vector<int> ();
//                 if (!vis[i] and adj[node][i])
//                 {
//                     vis[i] = 1;
//                     q.push(i);
//                 }
//             }
//         }
//         return bfs;
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         if(prerequisites.size()==0)
//         {
//             vector<int> ans;
//             for(int i =0;i<numCourses;i++)
//                 ans.push_back(i);
//             return ans;
//         }
//         vector<vector<int>> graph(numCourses,vector<int> (numCourses,0));
//         vector<int> ans;
//         for (auto i : prerequisites)
//         {
//             graph[i[1]][i[0]] = 1;
//         }
//         for(int i =0;i<numCourses;i++)
//         {
//             vector<int> cur = bfstraversal(i,graph,numCourses);
//             if(cur.size()==0)
//                 return cur;
//             if(cur.size()>ans.size())
//                  ans = cur;
//         }
//         unordered_map<int,bool> mp;
//         for(auto i:ans)
//         {
//             mp[i] = true;
//         }
//         for(int i =0;i<numCourses;i++)
//         {
//             if(mp[i]==false)
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };
class Solution
{
public:
    void dfstraversal(int v, vector<vector<int>> &adj, int numcor, vector<int> &cnt, vector<int> &dfs, vector<int> &vis)
    {
       // cout<<v<<endl;

        int node = v;
        dfs.push_back(node);
        for (auto i:adj[node])
        {
           // cout<<!vis[i]<<" "<<cnt[i]<<endl;
            if (!vis[i] and cnt[i]==1)
            {
                vis[i] = 1;
                dfstraversal(i,adj,numcor,cnt,dfs,vis);
            }
            else if(!vis[i] and cnt[i]>1)
            {
                cnt[i]--;
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> cnt(numCourses, 0);
        vector<int> visit(numCourses,0);
        vector<int> ans;
        for (auto i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            cnt[i[0]]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (cnt[i] == 0)
            {
                dfstraversal(i, adj, numCourses, cnt,ans,visit);
            }
        }
        for(int i =0;i<numCourses;i++)
        {
            cout<<i<<" = ";
            for(auto j:adj[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        if(ans.size()!=numCourses)
            return vector<int> ();
        return ans;
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}