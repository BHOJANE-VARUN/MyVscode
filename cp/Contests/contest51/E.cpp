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
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    if(m%2)
    {
        int i =0,j=0;
        int ct1 =0,ct2 =0;
        while(i<str.length())
        {
            if(str[i]=='1')
            ct1++;
            i++;
        }
        while(j<str.length())
        {
            if(str[j]=='1') ct2++,ct1--;
            if(ct1==ct2)
            {
                j++;
                break;

            }
          
            j++;
        }
        //cout<<j<<endl;
        int ans =0;
        while(str[j]!='1' and j<str.length()) ans++,j++;
        cout<<ans+1<<endl;
    }
    else{
        int last =0,first =0;
        int i =0,j=str.length()-1;
        while(i<str.length() and str[i]!='1') first++,i++;
        while(j>=0 and str[j]!='1') last++,j--;
        cout<<i<<" "<<j<<endl;
        if(i==str.length())
        {
            cout<<str.length()*m<<endl;
        }
        else
        cout<<max(first,last)<<endl;
    }
 }

//dusro ka code copy karne se khar nahi chalta bhai
}