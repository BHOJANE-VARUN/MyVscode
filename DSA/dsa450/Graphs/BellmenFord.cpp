#include<bits/stdc++.h>
using namespace std;
//negetive cycle dectection
bool bellmoncycle(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] =0;
    for(int i =1;i<n;i++)
    {   
        for(int j =0;j<=n;j++)
        {int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(dist[u]!=1e9 and (dist[u]+w)<dist[v])
        {
            dist[v] = dist[u] +w;
        }
     }
    }
    bool flag =0;
     for(int i =1;i<=n;i++)
        {int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (dist[u] != 1e9 and (dist[u] + w) < dist[v]) {
        flag = 1;
        }
     }
    if(flag ==0)
    {
        return 1;
    }
    return 0;
}
//shortest distance
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

 

    vector<int> dist(n+1,(int) 1e8);

    dist[src] = 0;

 

    for(int k = 1 ; k <= n-1 ; k++){

        for(int i = 0 ; i < m ; i++){

            if(dist[edges[i][1]] > dist[edges[i][0]] + edges[i][2]){

                dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];

            }

        }

    }

    return dist;

}
int main()
{
    return 9;
}