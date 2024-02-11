#include <bits/stdc++.h> 
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> mp;
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for(int i =0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    queue<int> q;
    parent[s] = -1;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int front = q.front();
		q.pop();
        for(auto i:mp[front])
        {
             if((!visited[i]))
            {   
				visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int temp = t;
	ans.push_back(t);
    while (temp!=s)
    {   
        temp = parent[temp];
		ans.push_back(temp);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    return 0;
}