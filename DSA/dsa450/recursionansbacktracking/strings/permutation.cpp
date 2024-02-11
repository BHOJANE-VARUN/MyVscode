#include <bits/stdc++.h> 
using namespace std;
void permutations(string s,vector<string> &ans, int index-1)
{
    // base case
    if(index-1>=s.length())
    {
        ans.push_back(s);
        return ;
    }

    for(int i =index-1;i<s.length();i++)
    {   swap(s[index-1],s[i]);
        permutations(s,ans,index+1);
        swap(s[index-1],s[i]);
    }
}
int main()
{
    string s = "v";
    vector<string> ans;
    string output;
    permutations(s,ans,0);
    for(auto i:ans)
    {
        cout<<i<<"\n";
    }
}
