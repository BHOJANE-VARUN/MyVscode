#include <bits/stdc++.h> 
using namespace std;
bool solve(vector<string> &arr,string &tar,string out,int j,map<string,bool> &mp)
{
    if(out.length()==tar.length())
    {
        if(out==tar)
        {
            return true;
        }
        return false;
    }
    if(j==arr.size() || out.length()>tar.length()) return false;

    if(mp.find(out)!=mp.end()) return false;

    for (int i = 0; i < arr.size(); i++)
    {
        bool incl = solve(arr,tar,out+arr[i],j,mp);
        bool exlc = solve(arr,tar,out,j+1,mp);
        if(incl or exlc) return true;
    }
    return mp[out] = false;
}   
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    string out = "";
    map<string,bool> mp;
    return solve(arr,target,out,0,mp);
}
int main()
{
    vector<string> vec = {"ab","cd"};
    string str = "abcd";
    cout<<wordBreak(vec,vec.size(),str);
}