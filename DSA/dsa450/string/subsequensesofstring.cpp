#include <bits/stdc++.h>
#define lop(i,s,e) for(int i=s;i<e;i++)
#define whi(e) while(i<e)
#define l(str) str.length()
using namespace std;
vector<string> subsequences(string str){
	int len = l(str);
	vector<string> ans= {""};
	for(int i =0;i<len;i++)
    {   int size = ans.size();
      for(int j =0;j<size;j++)
      {
        string temp=ans[j];
        temp.push_back(str[i]);
        ans.push_back(temp);

      }  
    }
  auto it = ans.begin();
  ans.erase(it);
	return ans;
}
int main()
{
    string st = "acbaab";
    vector<string> test = subsequences(st);
    for(auto i:test)
    {
      cout<<i<<"\n";
    }
}