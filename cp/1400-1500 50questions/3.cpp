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
    int n,k;
    cin>>n>>k;
    int *arr = new int[n];
    int temp;
    vector<int> odd,even;
    int oddsum =0,evensum=0;
    for(int i =0;i<n;i++)
    {
       cin>>temp;
       arr[i] = temp;
       if(i%2)
       {
          odd.push_back(arr[i]);
          oddsum += arr[i];
       }
       else {
            even.push_back(arr[i]);
            evensum += arr[i];
        }
    }
    if(oddsum>evensum)
    {
        cout<<Y<<endl;
        continue;
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int lef = even.size(),olef = odd.size();
    for(int i =0;i<min(k,min(lef,olef));i++)
    {
        oddsum += even[even.size()-1-i];
        oddsum -= odd[i];
        evensum += odd[i];
        evensum -= even[even.size()-1-i];
    }
    if(oddsum>evensum) cout<<Y<<endl;
    else cout<<N<<endl;

}
//dusro ka code copy karne se khar nahi chalta bhai
}