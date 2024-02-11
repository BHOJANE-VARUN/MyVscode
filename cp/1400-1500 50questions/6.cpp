#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   
}
signed main()
{
test
{
    int n;
    cin>>n;
    int *arr =new int[n];
    int temp;
    int sumeven =0,sumodd =0;
    int odd =INT_MAX;
    int even = INT_MIN;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
       if((i+1)%2)
       {
           sumodd += abs(temp);
           odd = min(odd,temp);
       }
       else{
        sumeven += abs(temp);
        even = max(even,temp);
       }
    }
    cout<<(sumodd-odd+even)-(sumeven+odd-even)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}