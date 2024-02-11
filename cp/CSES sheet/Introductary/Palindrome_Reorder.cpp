#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{

{
   string str;
   cin>>str;
   unordered_map<char,int> mp;
   int maxi = INT_MIN;
   for(auto i:str)
   {
        mp[i]++;
   } 
    vector<char> ans(str.length());
    int i =0,j=str.length()-1;
    char ch;
    for(auto k:mp)
    {
        if(k.second%2)
        {
            ch = k.first;
           
        }
        else{
            int it = k.second/2;
            while(it--)
            {
                ans[i]=k.first;
                ans[j]=k.first;
                i++,j--;
                
            }
        }
    }
    while(i<=j)
    {
        ans[i]=ch;
        i++;
        mp[ch]--;
        if(mp[ch]==0 and i<=j)
        {
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }//120 - 24*3
    }
    for(auto i:ans) cout<<i;
}
//dusro ka code copy karne se khar nahi chalta bhai
}