#include <bits/stdc++.h> 
using namespace std;
void solve(vector<vector<string>> &ans,vector<vector<string>> & arr,int row,vector<string> output)
{
    if(row==arr.size())
    {
        ans.push_back(output);
        return;
    }

    for(int i =0;i<arr[0].size();i++)
    {
        output.push_back(arr[row][i]);
        solve(ans,arr,row+1,output);
        output.pop_back();
    }

}
void createSentences(vector < vector < string > > & arr, vector < vector < string > > & ans) {
    solve(ans,arr,0,vector<string> {});
}
int main()
{
    
    vector<vector<string>> arr = {{"you","we"},{"sleep","drink"}};
    vector<vector<string>> ans; createSentences(arr,ans);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}