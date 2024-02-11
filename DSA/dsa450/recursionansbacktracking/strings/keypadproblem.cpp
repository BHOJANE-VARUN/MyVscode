#include <bits/stdc++.h> 
using namespace std;
void keypad(int index,string map[],vector<string> &ans,string s,string output)
{   if(index>=s.length())
    {   ans.push_back(output);
        return ;
    }
    int element = s[index]-'0';
    string mapping = map[element];

    for(int i =0;i<mapping.length();i++)
    {
        output.push_back(mapping[i]);
        keypad(index+1,map,ans,s,output);
        output.pop_back();
    }
}
int main()
{
    string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s;
    cin>>s;
    cout<<"\n";
    string output;
    vector<string> ans;
    keypad(0,map,ans,s,output);
    for(auto i:ans)
    {
        cout<<i<<"\n";
    }
}
