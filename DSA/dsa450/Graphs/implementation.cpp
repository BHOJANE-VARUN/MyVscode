#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> mp;
    void addedge(int v,int u,bool direction =0)
    {
        mp[v].push_back(u);
        if(!direction)
        {
            mp[u].push_back(v);
        }
    }
    void printadjList()
    {
        for(auto i:mp)
        {
            cout<<i.first<<"->";
            for(auto k:i.second)
            {
                cout<<k<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{   Graph g;
    for(int i =0;i<4;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.printadjList();
}