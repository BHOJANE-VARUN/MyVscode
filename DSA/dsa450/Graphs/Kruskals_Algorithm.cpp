#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b)
{
   return a[2]<b[2];
}
void makeunion(vector<int> &rank,vector<int> &parent,int u,int v)
{
   if(rank[u]>rank[v])
   {
      parent[v] = u;
   }
   else if(rank[u]<rank[v])
   {
      parent[u] = v;
   }
   else{
      parent[v] = u;
      rank[u]++;
   }
}
int findparent(vector<int> &parent,int u)
{
   if(parent[u]==u)
   {
      return u;
   }
   return parent[u] = findparent(parent,parent[u]);
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
   vector<int> parent(n),rank(n,0);
   for(int i =0;i<n;i++)
   {
      parent[i] = i;
   }
   sort(edges.begin(),edges.end(),cmp);
   int ans =0;
   for(int i =0;i<n;i++)
   {
      int u = findparent(parent,edges[i][0]);
      int v = findparent(parent,edges[i][1]);
      int w = edges[i][2];
      if(u!=v)
      {
         ans += w;
         makeunion(rank,parent,u,v);
      }
   }
   return ans;
}
int main()
{
   return 0;
}