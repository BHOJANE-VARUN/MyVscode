#include<bits/stdc++.h>
using namespace std;
// void inputarrInt(int *arr,int n)
// {   int temp;
//     for(int i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
// int main()
// {
// int t;
// cin>>t;
// while (t--)
// {   
//     int si;cin>>si;
//    string n;
//    cin>>n;
//    int ans = 1;
//    for(int i =2;i<n.length();i++)
//    {    

//         int cur =0;
//         int one = n[i-2]-'0';
//         int second = n[i-1]-'0';
//         int last = n[i] - '0';
//         if((one & second)==last)
//         {
//             cur++;
//         }
//         if((one | second)==last)
//         {
//             cur++;
//         }
//         if((one ^ second)==last)
//         {
//             cur++;
//         }
//         if(cur==0)
//         {
//             ans =0;
//             break;
//         }
//         else{
//             ans *= cur;
//         }
//        // cout<<one<<second<<last<<endl;
//    }
//    cout<<ans<<endl;
// }

// }
#include <iostream>
using namespace std;
long long mod = 1e9 + 7;
// #include<bits/stdc++.h>
// using namespace std;
// void inputarrInt(int *arr,int n)
// {   int temp;
//     for(int i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
int t;
cin>>t;
while (t--)
{
   int si;
   cin>>si;
   string n;
   cin>>n;
   long long ans = 1;
   for(int i =2;i<n.length();i+=2)
   {    
        int cur =0;
        int one = n[i-2]-'0';
        int second = n[i-1]-'0';
        int last = n[i] - '0';
        if((one & second)==last)
        {
            cur++;
        }
        if((one | second)==last)
        {
            cur++;
        }
        if((one ^ second)==last)
        {
            cur++;
        }
        if(cur==0)
        {
            ans =0;
            break;
        }
        else{
            ans = (cur* ans)%mod;
        }
   }
   cout<<ans<<endl;
}

}
