#include <bits/stdc++.h> 
using namespace std;
string removeVowels(string inputString) {
    string ans="";
    string vow = "aeiouAEIOU";
    for(int i =0;i<inputString.length();i++)
    {
        if(vow.find(inputString[i])<vow.length())
        {
            continue;
        }
        else{
            ans.push_back(inputString[i]);
        }
    }
    return ans;
}
int main()
{
    string str = "AAAA";
    str = removeVowels(str);
    cout<<str;
}
