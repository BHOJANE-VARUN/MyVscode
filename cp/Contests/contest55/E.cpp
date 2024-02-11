#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, p, q, r, ans, i, j;
    
    cin>>t;
    
    for(;t--;)
    {
        cin>>p>>q>>r;
        
        ll c[21];
        
        for(i=0; i<=20; i++){
            c[i]=0;
        }
        
        for(i=0; i<20; i++)
        {
            c[i]=c[i]+(p%2)+(q%2)+(r%2);
            p/=2;
            q/=2;
            r/=2;
        }
        
        ans=1;
        
        for(i=0; i<20; i++)
        {
            if(c[i]==1){
                ans=0;
                break;
            }else if(c[i]==3){
                ans=ans*4;
            }
        }
        cout<<ans<<"\n";
    }
    
}