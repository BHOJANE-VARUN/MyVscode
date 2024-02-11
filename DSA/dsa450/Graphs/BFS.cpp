#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
void helper(vector<vector<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node)
{
    queue<int> que;
    que.push(node);
    visited[node] = true;
    while(!que.empty())
    {   
        int ele = que.front();
    
        que.pop();
        ans.push_back(ele);
        
        for(auto i:adj[ele])
        {
            if(!visited[i])
            {
                que.push(i);
                visited[i] = true;
            }
        }
    }
    
}
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.

    
    unordered_map<int,bool> visited;
    vector<int> ans;
    helper(adj, visited, ans, 0);
    return ans;
}
int main()
{
    return 0;
}