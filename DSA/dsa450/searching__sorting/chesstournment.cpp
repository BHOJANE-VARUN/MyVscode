#include <bits/stdc++.h> 
using namespace std;
int ind;
bool predictor(vector<int> &pos,int dist)
{
    int prepos =0;
    int count =1;
    for(int i =1;i<pos.size();i++)
    {
        if(pos[i]-prepos>dist) count++,prepos = pos[i];
        if(count==ind)return true;
    }
    return false;

}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
    ind = c;
    int m;
    int low = 1,high = positions[n-1];
    while (high-low>1)
    {
         m =(high+low)/2;
        if(predictor(positions,m)) low=m;
        else high=m-1;
    }
    return high<m?high:m;
    
}
int main()
{
    vector<int> pos = {1,2,3,4,6};
    int c = 3,n = pos.size();
     cout<<chessTournament(pos,n,c);
}