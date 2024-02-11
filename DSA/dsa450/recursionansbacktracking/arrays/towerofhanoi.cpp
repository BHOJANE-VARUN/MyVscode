#include <bits/stdc++.h>
using namespace std;
void operations(int tno,int ttar,int th,int n, vector<vector<int>> &ans)
{
    if(n==2)
    {
            vector<int> temp = {tno,th};
            ans.push_back(temp);
            temp[0]=tno,temp[1]=ttar;
            ans.push_back(temp);
            temp[0]=th,temp[1]=ttar;
            ans.push_back(temp);
            return;
    }
    operations(tno,th,ttar,--n,ans);
    vector<int> temp={tno,ttar};
    ans.push_back(temp);
    operations(th,ttar,tno,n--,ans);
    return;

    
}
vector<vector<int>> towerOfHanoi(int n)
{   vector<vector<int>> ans;
    if(n==1)
    {
        vector<int> temp ={1,2};
        ans.push_back(temp);
        return ans;
    }
    operations(1,3,2,n,ans);
    return ans;
}
int main()
{
    vector<vector<int>> ans = towerOfHanoi(3);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    
}