#define ll long long int
#include<bits/stdc++.h>
#define for0(i,b) for(ll i=0;i<b;++i)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) for(ll i=0;i<n;++i) cin>>a[i];
#define pb push_back
#define all(v) v.begin(),v.end()
#define dis(v) for(auto i:v)cout<<i<<" ";cout<<endl;
#define display(arr,n) for(int i=0; i<n; i++)cout<<arr[i]<<" ";cout<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL));
#define l(a) a.length()
#define fr first
#define sc second
#define mod 1000000007
#define endl '\n'
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;

//0^1 0&1 1^0 10001 01000  1100 1101
/*{{  001
   {  010      100
      011      010
      100
      101 
      222
   */
int bit(int n){
  int cnt=0;
    while(n){
        n/=2; cnt++;
    }
    return cnt;
}
void solve(){
    ll n; cin>>n;
    ll a[n];
    for0(i,n) cin>>a[i]; 
    vector<vector<ll>>v;
   
    vector<ll>bits(32,0);
     v.push_back(bits);
    for0(i,n){
        int leftpos= bit(a[i]);
        bits[leftpos]++;
        v.push_back(bits);
    }
    ll k; cin>>k;
    while(k--){
        ll a,b,c; cin>>a>>b>>c;
        n=b-a+1;
        ll  idx=bit(c);
       
        cout<<n-((v[b][idx])-(v[a-1][idx]))<<"\n";
    }
}

int main()
{
    fast
    int t; cin>>t;
    
    while(t--) solve();
    return 0;
}