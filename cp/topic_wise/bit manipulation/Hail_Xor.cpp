// #include<bits/stdc++.h>
// #define int long long int
// #define Y "YES"
// #define N "NO"
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// signed main()
// {
// test
// {
//     int n,x;
//     cin>>n>>x;
//     int *arr = new int[n];
//     for(int i =0;i<n;i++)
//     {
//       cin>>arr[i];
//     }
    
//     vector<int> bits(32,0);
//     int ct =0;
//     for(int i =0;i<32;i++)
//     {
//         for(int k =0;k<n;k++)
//         {
//             if(((1<<i)&arr[k])>0)
//             {
//                 if(ct<x)
//                 bits[i]--;
//                 else bits[i]++;
//             }
//         }
//     }
//     for(int i =0;i<32;i++)
//     {
//         for(int k =n-1;k>=0;k--)
//         {
//             if(((1<<i)&arr[k])>0)
//             {
//                 if(bits[i])
//                 {
//                     bits[i]--;
//                 }
//                 else{
//                     arr[k] = (arr[k]^(1<<i));
//                 }
//             }
//         }
//     }
//     for(int i =0;i<n;i++) cout<<arr[i]<<" ";
//     cout<<endl;
// }
// //dusro ka code copy karne se khar nahi chalta bhai
// }
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
    int n,x;
    cin>>n>>x;
    int *arr = new int[n];
    for(int i =0;i<n;i++)
    {
      cin>>arr[i];
    }
    vector<int> mem(32,0);
    for(int i =0;i<n-1;i++)
    {
        for(int k =0;k<32;k++)
        {
            if(((1<<k)&arr[i])>0)
            {
                if(mem[k]==1)
                {
                    mem[k] =0;
                    arr[i] =  (arr[i]^(1<<i));
                }
                else{
                    mem[k] =1;
                    x--;
                }
                if(x==0) break;
            }
        }
        if(x==0) break;
    }
    for(int k =0;k<32;k++)
    {
        if(mem[k]==1)
        {
            arr[n-1] = (arr[n-1]^(1<<k));
        }
    }
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}