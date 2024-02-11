#include <bits/stdc++.h> 
using namespace std;
vector<pair<char, int>> mapit(string str) {
    int n = str.length();
    vector<pair<char, int>> ans(n);
    int len = 0; // Length of the longest proper prefix that is also a suffix

    ans[0] = make_pair(str[0], -1);

    for (int i = 1; i < n; i++) {
        while (len > 0 && str[i] != str[len])
            len = ans[len - 1].second + 1;

        if (str[i] == str[len]) {
            len++;
        } else {
            len = 0;
        }

        ans[i] = make_pair(str[i], len - 1);
    }

    return ans;
}

int checkpattern(string pattern,string main)
{
    vector<pair<char,int>> pi_table =mapit(pattern);
    int j =0;
    int ind = -1;
    int ans =0;
    while(j<main.length())
    {
        if(main[j]==pattern[ind+1])
        {
            j++,ind++;
            if(ind+1==pattern.length())
            {
            ans++;
            ind = -1;
            }
        }
        else{

            if(ind!=-1)ind = pi_table[ind].second;
            else{j++;}
            
        }
        
        
    }
    return ans;
}
int main()
{
    string pattern = "aab";
    vector<pair<char,int>> asn = mapit(pattern);
    for(auto i:asn)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    string main = "aabaab";
    int ans = checkpattern(pattern,main);
    cout<<ans;
    
}