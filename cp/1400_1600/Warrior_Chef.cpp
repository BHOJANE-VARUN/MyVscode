// #include<bits/stdc++.h>
// using namespace std;
// int inputarrInt(int *arr,int n)
// {   int temp;
//     int maxi = INT_MIN;
//     for(int i =0;i<n;i++)
//     {   
//         cin>>temp;
//         arr[i] = temp;
//         maxi = max(maxi,temp);
//     }
//     return maxi;
// }
// bool check(int *arr,int n,int r,int h)
// {
//     for(int i =0;i<n;i++)
//     {
//         if(arr[i]<=r)
//         {
//             continue;
//         }
//         else{
//             if(h>arr[i])
//             {
//                 h -= arr[i];
//             }
//             else{
//                 return false;
//             }
//         }

//     }
//     return true;
// }
// int main()
// {
// int t;
// cin>>t;
// while (t--)
// {
//     int n,h;
//     cin>>n>>h;
//     int *arr = new int[n];
//     int end = inputarrInt(arr,n);
//     int s =0;
//     int mid;
//     while (s<end)
//     {
//         mid = (s+end)/2;
//         if(check(arr,n,mid,h))
//         {
//             end = mid;
//         }
//         else{
//             s = mid + 1;
//         }
//     }
//     cout<<mid<<endl;
// }

// }
#include <iostream>
#include<limits.h>
using namespace std;

// #include<bits/stdc++.h>
// using namespace std;
int inputarrInt(int *arr,int n)
{   int temp;
    int maxi = INT_MIN;
    for(int i =0;i<n;i++)
    {   
        cin>>temp;
        arr[i] = temp;
        maxi = max(maxi,temp);
    }
    return maxi;
}
bool check(int *arr,int n,int r,int h)
{
    for(int i =0;i<n;i++)
    {
        if(arr[i]<=r)
        {
            continue;
        }
        else{
            if(h>arr[i])
            {
                h -= arr[i];
            }
            else{
                return false;
            }
        }

    }
    return true;
}
int main()
{
int t;
cin>>t;
while (t--)
{
    int n,h;
    cin>>n>>h;
    int *arr = new int[n];
    int end = inputarrInt(arr,n);
    int s =0;
    int mid;
    int ans;
    while (s<=end)
    {
        mid = (s+end)/2;
        if(check(arr,n,mid,h))
        {
            ans = mid;
            end = mid-1;
        }
        else{
            s = mid + 1;
        }
    }
    cout<<ans<<endl;
}

}
