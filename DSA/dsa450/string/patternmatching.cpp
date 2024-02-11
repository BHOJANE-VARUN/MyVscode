#include <bits/stdc++.h>
#define lop(i,s,e) for(int i=s;i<e;i++)
#define whi(e) while(i<e)
#define l(str) str.length()
using namespace std;
vector<int> stringMatch(string text, string pattern) {
	int hash = 0;
    int cur = 0;
    int count =0;
    vector<int> ans;
    for(int i =0;i<text.length();i++)
    {
        hash += (int)text[i];
        
    }
    for(int i =0;i<text.length();i++)
    {
        cur += (int)pattern[i];
        
    }
    for(int i=text.length()-1;i<pattern.length();i++)
    {
        if(cur==hash)
        {
            string temp = pattern.substr(i-text.length()+1,text.length());
            if(temp==text)
            {
                count++;
                ans.push_back(i-text.length()+1);
            }
        }
        else
        {
            cur -= (int)pattern[i-text.length()+1];
            cur+= (int)pattern[i+1];
        }
        
    }
    ans.insert(ans.begin(),count);
    return ans;
}
int main(){
// ababacabab

// xyz
    string text = "aba";
    string pattern = "ababacabab";
    vector<int> ans = stringMatch(text,pattern);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
