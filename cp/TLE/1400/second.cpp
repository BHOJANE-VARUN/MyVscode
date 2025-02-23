#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
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
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int first =INT_MAX,second =INT_MAX;
    int ans =0;
    for(int i =0;i<n;i++)
    {
        if(first>=arr[i] and second>=arr[i])
        {
            if(first-arr[i]<=second-arr[i])
            {
                first = arr[i];
            }
            else second = arr[i];
        }
        else if(first>=arr[i])
        {
            first = arr[i];
        }
        else if(second>=arr[i])
        {
            second = arr[i];
        }
        else{
            ans++;
            if(first<=second)
            {
                first = arr[i];
            }
            else second = arr[i];
        }
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se ghar nahi chalta bhai
}