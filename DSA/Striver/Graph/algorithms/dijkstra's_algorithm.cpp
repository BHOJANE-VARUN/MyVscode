class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> cost(N,INT_MAX);
        vector<vector<int>> adj(N);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        set<pair<int,int>> s;
        cost[src] =0;
        s.insert({0,src});
        while (s.size())
        {
            int co = (*s.begin()).first,ele = (*s.begin()).second;
            s.erase(s.begin());
            for(auto i:adj[ele])
            {
                if(cost[i]>co+1)
                {
                    cost[i] = co+1;
                    s.insert({cost[i],i});
                }
            }
        }
        for(int i =0;i<N;i++)
        {
            if(cost[i]==INT_MAX)
            {
                cost[i] = -1;
            }
        }
        return cost;
    }
};