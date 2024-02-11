#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subseq(int index,string &s,string output,vector<string> &ans)
{
    if(index>=s.length())
    {
        ans.push_back(output);
        return ;
    }

    //exclude
    subseq(index+1,s,output,ans);

    output.push_back(s[index]);
    subseq(index+1,s,output,ans);
}
int main()
{
    vector<string> ans;
    string output;
    string s = "varun";
    subseq(0,s,output,ans);
    for(auto i:ans)
    {
        cout<<i<<"\n";
    }
}