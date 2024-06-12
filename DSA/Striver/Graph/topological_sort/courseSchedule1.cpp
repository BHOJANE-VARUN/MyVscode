class Solution {
public:
        void dfs(vector<vector<int>> &adj,int src,int v,vector<int> &vis,bool &f)
    {
        if(f==1)
            return;
        vis[v] = src;
        for(auto i:adj[v])
        {
            if(vis[i]!=-1 and vis[i]==src)
            {
                f =1;
                return;
            }
            else if(vis[i]==-1)
            {
                dfs(adj,src,i,vis,f);
            }
        }
        vis[v] = -2;
    }
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> visit(V,-1);
        bool f= false;
        for(int i =0;i<V;i++)
        {
            if(visit[i]==-1)
            {
                dfs(adj,i,i,visit,f);
            }
            if(f)
            {
                return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> arr(numCourses);
        for(auto i:prerequisites)
        {
            arr[i[1]].push_back(i[0]);
        }
        return !(isCyclic(numCourses,arr));
    }
};