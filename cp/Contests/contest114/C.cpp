#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputarrll(ll *arr,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
test
{
    int n;
    cin>>n;
    string str;
    cin>>str;

    vector<char> ans(n,'P');
    for(int i =n-1;i>=(n/2)-1;i--)
    {
       
            if(str[i]=='P')
            {
                ans[i]='S';
               
            }
            else if(str[i]=='R')
            {
                continue;
            }
            else ans[i]='R';
        
    }
    int ct =0,lol =0;
    for(int i =(n/2)-2;i>=0;i--)
    {
        if(str[i]=='R') ct++;
        lol++;  
    }

    for(auto i:ans)
    {
        if(ct && ans[i]!='P')
        {
            ans[i]='P',ct--;
        }
    }
    for(auto i:ans) cout<<i;
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}