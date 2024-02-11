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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int index =-1;
    for(int i =0;i<str.length()-1;i++)
    {
        if(str[i]>str[i+1]) 
        {
            index = i;
        }
        else cout<<str[i];
    }
    
}
//dusro ka code copy karne se khar nahi chalta bhai
}