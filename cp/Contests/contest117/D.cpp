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
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}

signed main()
{
test
{
    int a,b;
    cin>>a>>b;
    int req = abs(a-b);
    int low = 1,high = (1e5)-1;
    int mid = (low+high)/2;
    int ele = -1;
    while(low<=high)
    {
        mid = (low+high)/2;
        ele = (mid*(mid+1)*1ll)/2;
        //cout<<low<<" "<<high<<endl;
        if(req==ele)
        {
            break;
        }
        else if(ele<req)
        {
            low = mid+1;
        }
        else{
            high =mid-1;
        }
    }
    while(ele!=req and abs(ele-req)%2!=0)
    {
        mid++;
        ele = (mid*(mid+1)*1ll)/2;
    }
    cout<<mid<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}