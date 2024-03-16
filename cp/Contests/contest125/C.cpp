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
    //3 4 6 4
    //odd even even even
    // 
    //0 = alice and 1= bob 
    //0 1 2 3 4 odd = alice even = bob
    // even even even
    //2
    //alice = bob wins
   // 1+2+4+2 = 9
   // 9 = alice,8 = bob,7=alice,5,3,1
   // even = alice,odd = bob
   // even = bob,odd = alice
   // no of ones = odd and even 
    // alice = no+1/2 ,bob = n-alice
    int n;
    cin>>n;
    int *arr = new int[n];
    int noone = 0;
    int moves = 0;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
        {
            noone++;
        }
        else{
            moves += arr[i]-2;
        }
    }
    int alice = (noone+1)/2;
    int bob = noone-alice;
    int rem = n-noone;
    if(moves%2)
    {
        alice += rem;
    }
    else bob += rem;
    if(alice>bob)
    {
        cout<<"Alice"<<endl;
    }
    else if(alice<bob)
    {
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
}
//dusro ka code copy karne se ghar nahi chalta bhai
}