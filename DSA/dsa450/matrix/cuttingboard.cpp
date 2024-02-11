#include <bits/stdc++.h> 
using namespace std;
int boardCutting(vector<int>& horizontal, vector<int>& vertical, int m, int n)
{
    long long  col = 1,row=1;
    long long  ans =0;
    long long mod = 1e9 +7;
    multimap<int,char,greater<int>> map;
    for(auto i:horizontal)
    {   pair<int,char> temp = {i,'h'};
        map.insert(temp);
    }
    for(auto i:vertical)
    {   pair<int,char> temp = {i,'c'};

        map.insert(temp);
    }
    for(auto i = map.begin();i!=map.end();++i)  
    {
        if((*i).second =='h')
        {
            ans =(ans+ ((*i).first *( row%mod)))%mod;
            col++;
        }
        else{
            ans = (ans+((*i).first  * (col%mod)))%mod;
            row++;
        }
    }
    return ans;
}
int main()
{
    vector<int> hor = {1};
    vector<int> vec = {3};
    int m = 2;
    int n = 2;
    cout<<boardCutting(hor,vec,m,n);
}
