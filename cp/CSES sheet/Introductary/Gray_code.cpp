#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void binaryform(int num,int si)
{
    int temp =1;
    if((temp<<si-1)&num) cout<<1;
    else cout<<0;
    for(int i=si-1;i>0;i--)
    {
        int first =0,second =0;
        if(((temp<<i)&num))
        {
            first =1;
        }
        else first =0;
        if(((temp<<i-1)&num))
        {
            second =1;
        }
        else second =0;
        cout<<(first^second);
    }
    cout<<endl;
}
signed main()
{

{
    int n;
    cin>>n;
    int count = pow(2,n);
    for(int i =0;i<count;i++)
    {
        binaryform(i,n);
    }
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}