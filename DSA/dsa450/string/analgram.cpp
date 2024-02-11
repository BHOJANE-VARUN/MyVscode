#include <bits/stdc++.h>
using namespace std; 
vector<vector<string> > groupAnagramsTogether(vector<string> &strList)
{   vector<vector<string>> ans;
    vector<int> count;
    for(auto i:strList)
    {   long long sum =0;
        for(auto c:i)
        {
            sum+= ((long long)c)^2;
        }
        int flag =0;
        for(int k=0;k<count.size();k++)
        {
            if(sum==count[k])
            {   
                flag =1;
                ans[k].push_back(i);
            }
        }
        if(flag==0)
        {   vector<string> temp;
            temp.push_back(i);
            ans.push_back(temp);
            count.push_back(sum);

        }
    }
    return ans;
}

int main()
{
    vector<string> test = {"abab", "baba", "aabb" ,"abbc"};
    vector<vector<string>> varun = groupAnagramsTogether(test);
    for(auto i:varun)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}