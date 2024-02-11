#include <bits/stdc++.h>
using namespace std;
int dss(vector<int> &d)
{   sort(d.begin(),d.end());
    vector<vector<int>> ans={{}};
    for(int j =0;j<d.size();j++)
    {
        int siz = ans.size();
        for(int i=0;i<siz;i++)
        {
            vector<int> temp = ans[i];
            int s = temp.size();
            if(s!=0)
            {if(temp[s-1]==d[j])
            {
                continue;
            }}
            temp.push_back(d[j]);
            ans.push_back(temp);
        }
        
        
    }
    return ans.size()-1;
}
int main()
{
    vector<int> test = {7 ,2 ,2, 1 ,1 ,1 ,1};
    int an = dss(test);
    cout<<an;
}