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
test
{
    int n;
    cin>>n;
    int temp = n;
    int msb =0;
    for(int i =0;i<31;i++)
    {
        if(((1<<i)&n)>0)
        {
            msb = i;
        }
    }
    int i =0;
    int ans =0;
    int prv =-1;
    while(i<msb)
    {
        if(((1<<i)&n)>0 and prv==-1)
        {
            prv = i;
            i++;
        }
        else if(((1<<i)&n)>0)
        {
            i++;
        }
        else{
            if(prv!=-1)
            {
                ans += (1<<prv);
                if(abs(prv-i)>1)
                ans += (1<<i);
                prv =-1;
                i++;
            }
            else{
                i++;
            }
        }
    }
    cout<<ans<<endl;
    // while(msb!=0 and ((1<<msb)&n)>0 and ((1<<(msb-1))&n)>0) msb--;
    // int ans =0;
    // for(int i =0;i<msb;i++)
    // {
    //         if(((1<<i)&n)>0)
    //         {
    //                 for(int i =0;i<31;i++)
    //                 {
    //                     if(((1<<i)&ans)>0)
    //                     {
    //                         cout<<1;
    //                     }
    //                     else cout<<0;
    //                 }
    //                 cout<<endl;
    //                                     for(int i =0;i<31;i++)
    //                 {
    //                     if(((1<<i)&n)>0)
    //                     {
    //                         cout<<1;
    //                     }
    //                     else cout<<0;
    //                 }
    //             n = n + (1<<i);
    //             ans = ans + (1<<i);
    //         }
    // }
    // cout<<ans<<endl;
    // int ans =INT_MAX;
    // int f =0;
    // for(int i =1;i<vec.size();i++)
    // {
    //     if((vec[i]-vec[i-1])>1)
    //     {
    //         f = 1;
    //     }
    // }
    // int ele1,ele2;
    // if(f==0)
    // cout<<0<<endl;
    // else{
    //     int siz = vec.size()-1;
    //     int ans =0;
    //     while(abs(vec[siz]-vec[siz-1])==1 and siz>0) siz--;
    //     for(int i =0;i<=siz;i++)
    //     {
    //         if(((1<<vec[i])&n)>0)
    //         {
    //             n = n + (1<<vec[i]);
    //             ans = ans + (1<<vec[i]);
    //         }
    //     }
    //     cout<<ans<<endl;
    // }
    // for(int i =0;i<31;i++)
    // {
    //     if(((1<<i)&ele1)>0)
    //     {
    //         cout<<1;
    //     }
    //     else cout<<0;
    // }
    // cout<<endl;
    // for(int i =0;i<31;i++)
    // {
    //     if(((1<<i)&ele2)>0)
    //     {
    //         cout<<1;
    //     }
    //     else cout<<0;
    // }
    // cout<<endl;
    // for(int i =0;i<31;i++)
    // {
    //     if(((1<<i)&5929)>0)
    //     {
    //         cout<<1;
    //     }
    //     else cout<<0;
    // }
    // cout<<endl;
    // for(int i =0;i<31;i++)
    // {
    //     if(((1<<i)&ans)>0)
    //     {
    //         cout<<1;
    //     }
    //     else cout<<0;
    // }
    // cout<<endl;
    // for(auto i:vec) cout<<i<<" ";
    // cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}