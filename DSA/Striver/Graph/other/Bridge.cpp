void dfs3(int node, vector<int> &vis,vector<int> adj[], int parent, vector<int> &mini, vector<vector<int>> &ans)
{
    if(parent!=-1)
    {
        vis[node] = vis[parent] + 1;
        mini[node] = vis[parent] + 1;
    }
    for (auto &it : adj[node])
    {
        if (vis[it] == -1)
        {
            dfs3(it,vis,adj,node,mini,ans);
            mini[node] = min(mini[node], mini[it]);
            if (vis[node] < mini[it])
            {
                ans.push_back({node,it});
            }
        }
        else if (it != parent)
        {
            mini[node] = min(mini[node], mini[it]);
        }
    }
}
class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for(auto &i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<vector<int>> ans;
        vector<int> visit(n,-1),mini(n,-1);
        visit[0] = 0;
        mini[0] =0;
        dfs3(0,visit,adj,-1,mini,ans);
        for(auto i:visit) cout<<i<<" ";
        return ans;
    }
};