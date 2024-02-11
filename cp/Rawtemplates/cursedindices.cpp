#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrll(ll *arr,ll n)
{   ll temp;
    for(ll i =0;i<n;i++)
    {
        cin>>temp;
        arr[i] = temp;
    }
}
int main()
{
    test
    {
        ll n;
        cin>>n;
        ll* arr = new ll[n];
        inputarrll(arr,n);
        sort(arr,arr+n);
        //for(int i =0;i<n;i++) cout<<prefix[i]<<" ";
        ll sub = arr[0];
        ll ansnum =0;
        vector<int> ans;
        vector<int> autaulans;
        autaulans.push_back(arr[0]);
         //for(int i =0;i<n;i++) cout<<arr[i]<<" ";
        for(int i =1;i<n;i++)
        {
            // cout<<arr[i]<<" "<<(prefix[i]-sub)<<endl;
            if(arr[i]>(sub))
            {
                autaulans.push_back(arr[i]);
                sub += arr[i];
                continue;
            }
            else{
                ans.push_back(arr[i]);
                ansnum++;
            }
        }
        cout<<ansnum<<endl;
        for(auto k:autaulans)cout<<k<<" ";
        for(auto k:ans)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }

//dusro ka code copy karne se khar nahi chalta bhai
}
