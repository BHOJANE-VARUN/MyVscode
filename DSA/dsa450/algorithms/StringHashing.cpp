#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define mod 1000000007
const int maxsize = 1e5;
int inverse[maxsize+1];
int prefix[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int gethash(string &key)
{
    int value =0;
    int p =31;
    int p_power = 1;
    for(auto i:key)
    {
        value = (value + (i-'a'+1)*p_power)%mod;
        p_power = (p_power*p)%mod;
    }
    return value;
}
void _init_substring_hashing(string &str)
{
    int p = 31,p_power = 1;
    inverse[0] =1;
    prefix[0] = (str[0]-'a'+1);
    for(int i =1;i<str.size();i++)
    {
        char ch = str[i];
        p_power = (p_power*p)%mod;
        inverse[i] = binpow(p_power,mod-2,mod);
        prefix[i] = (prefix[i-1]+(ch-'a'+1)*p_power)%mod;
    }
}
int substring_hash(int l,int r)
{
    int result = prefix[r];
    if(l>0) result -= prefix[l-1];
    result = (result*inverse[l])%mod;
    return result;
}
signed main()
{
    string str = "abcd";
    string str2 = "xisabcdsdi";
    int hash = gethash(str);
    _init_substring_hashing(str2);
    for(int i =str.size()-1;i<str2.size();i++)
    {
        int l = i-str.size()+1,r = i;
        int cur = substring_hash(l,r);
        if(cur==hash) cout<<l<<" "<<r<<endl;
    }
//dusro ka code copy karne se ghar nahi chalta bhai
}