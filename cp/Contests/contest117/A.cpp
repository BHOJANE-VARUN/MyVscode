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
    int h,x,y1,y2,k;
    cin>>h>>x>>y1>>y2>>k;
    int first = h/x;
    if(h%x!=0) first++;
    int second = y1*k;
    if(h<second)
    {
        second = h/y1;
    if(h%y1!=0) second++;
    }
    else{
        int left = h-(y1*k);
        int y2money = left/y2;
        if(h%y2!=0) y2money++;
        second = k+y2money;
    }
    cout<<min(first,second)<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}