#include <bits/stdc++.h> 
using namespace std;
long long ans;
void recur(int n,int k,vector<int> &var)
{
    ans = n;
    if(ans<=0)return ;
    var.push_back(ans);
    recur(ans-k,k,var);
}
void uprecur(int n,int k,vector<int> &var)
{   
    if(ans>n)return ;
    var.push_back(ans);
    ans = ans+k;
    uprecur(n,k,var);
}
vector<int> printSeries(int n, int k)
{   
    vector<int> vec;
    recur(n,k,vec);
    uprecur(n,k,vec);
    return vec;
}
int main()
{
    vector<int> ans = printSeries(6,1);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}