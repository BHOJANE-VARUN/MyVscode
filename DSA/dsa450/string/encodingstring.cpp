#include <bits/stdc++.h> 
using namespace std;
string encode(string &message)
{   char curchar=message[0];
    int curcount =1;
    string ans;
    for(int i =1;i<message.length();i++)
    {
        if(message[i-1]!=message[i])
        {   ans.push_back(curchar);
            ans.append(to_string(curcount));
            curchar = message[i];
            curcount = 1;
        }
        else{
            curcount++;
        }
    }
    ans.push_back(curchar);
    ans.append(to_string(curcount));
    return ans;
}
int main()
{
    string str = "aaabbc";
    str = encode(str);
    cout<<str;
}