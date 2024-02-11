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
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    int *zeros = new int[n+1];
    int *ones = new int[n+1];
    ones[0]=0;
    zeros[0]=0;
    for(int i =0;i<n;i++){
        if(arr[i]==0 or arr[i]==1)
        {
            zeros[i+1]=zeros[i]+1;
        }
        else{
            zeros[i+1] = zeros[i];
        }
        if(arr[i]==1)
        {
            ones[i+1]=ones[i]+1;
        }
        else{
            ones[i+1] = ones[i];
        }
    }
    
    cout<<endl;
    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        int bad=0;
        if(l!=0)
         bad =zeros[r]-zeros[l-1];
        else bad = zeros[r];
        //cout<<bad<<endl;
        int ans = (r-l)*((r-l)+1)/2;
        bad = ((bad-1)*bad)/2;
        int one =0;
        if(l!=0)
         one =ones[r]-ones[l-1];
        else one = ones[r];
      // cout<<one<<endl;
      //cout<<one<<endl;
        one = (one*(one-1))/2;
        //cout<<one<<endl;
      // cout<<ans<<" "<<bad<<endl;
        cout<<ans-bad+one<<endl;
    }
    
}
//dusro ka code copy karne se khar nahi chalta bhai
}
