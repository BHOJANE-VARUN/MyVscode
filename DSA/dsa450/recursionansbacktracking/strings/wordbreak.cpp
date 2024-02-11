#include <bits/stdc++.h>
using namespace std;
bool valid(string &temp,vector<string> &dict)
{
    for(auto i:dict)
    {
        if(i==temp)
        {
            return true;
        }
    }
    return false;
}
void solve(string &s,vector<string> &dict,vector<vector<string>> &ans,vector<string> output,string temp,int index)
{
    if(index>=s.size()) 
    {  if(temp=="") 
       ans.push_back(output);
        return;
    }
    
    for( int i =index;i<s.size();i++)
    {
        temp.push_back(s[i]);
        if(valid(temp,dict))
        {   index = i;
            break;
        }
        else if(i==s.size()-1) return;
    }

    //exclude
    solve(s,dict,ans,output,temp,index+1);
    //include
    output.push_back(temp);
    solve(s,dict,ans,output,"",index+1);
    output.pop_back();

}
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    vector<vector<string>> ans;
    vector<string> output;
    solve(s,dict,ans,output,"",0);
    vector<string> ren;
    for(auto i:ans)
    {
        for(auto j:i)
        {   ren.push_back(j);
            ren.push_back(' ');
        }
    }
    return ren;
}
int main()
{
    string s = "godisnowherenowhere";
    vector<string> dict = {"god","is","no","now","where","here"};
    vector<vector<string>> ans = getAllValidSentences(s,dict);
    
}
