// #include<bits/stdc++.h>
// #define int long long int
// #define Y "YES"
// #define N "NO"
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// struct range
// {
//     pair<int,int> a;
//     int index,room;
//     bool operator <(range &b)
//     {
//         // if(a.second==b.a.second)
//         //     return a.first<b.a.first;
//         //  return a.second<b.a.second;
//         if(a.first==b.a.first)
//             return a.second<b.a.second;
//         return a.first<b.a.first;
//     }
// };
// signed main()
// {
//     int n;
//     cin>>n;
//     vector<range> arr(n);
//     vector<int> ans(n);
//     for(int i =0;i<n;i++)
//     {
//         cin>>arr[i].a.first>>arr[i].a.second; 
//         arr[i].index =i;
//     }
//     sort(arr.begin(),arr.end());
//     int ansnum = 1;
//     int i =0,j=1;
//     arr[0].room = 1;
//     ans[arr[0].index] = arr[0].room;
//     int cur = 2;
//     while(i<n and j<n)
//     {
//         if(arr[j].a.first>arr[i].a.second)
//         {
//             arr[j].room = arr[i].room;
//             i++;
//             ans[arr[j].index] = arr[j].room;
//         }
//         else{
//             arr[j].room = cur;
//             cur++;
//             ans[arr[j].index] = arr[j].room;
//         }
//         ansnum = max(ansnum,arr[j].room);
//         j++;
//     }
//     for(auto i:arr)
//     {
//         cout<<i.a.first<<" "<<i.a.second<<" "<<i.room<<endl;
//     }
//     // cout<<ansnum<<endl;
//     // for(auto i:ans) cout<<i<<" ";
// //dusro ka code copy karne se khar nahi chalta bhai
// }
// signed main()
// {
//     int n;
//     cin>>n;
//     vector<range> arr(n);
//     vector<int> ans(n);
//     for(int i =0;i<n;i++)
//     {
//         cin>>arr[i].a.first>>arr[i].a.second; 
//         arr[i].index =i;
//     }
//     sort(arr.begin(),arr.end());
//     set<array<int,2>> st;
//     int cur = 1;
//     int ansnum = 0;
//     for(int i =0;i<n;i++)
//     {
//         auto it = st.lower_bound(arr[i].a.first);
//         if(it!=st.begin())
//         {
//             it--;
//             ans[arr[i].index] = (*it)[1];
//             st.erase(it);
//            // cout<<arr[i].a.first<<" "<<(*it)<<endl;
//         }
//         else{
//             ans[arr[i].index] = cur;
//             cur++;
//         }
//         ansnum = max(ans[arr[i].index],ansnum);
//         array<int,2> temp = {arr[i].a.second,ans[arr[i].index]};
//         st.insert(temp);
//         // for(auto i:st) cout<<i<<" ";
//         // cout<<endl;
//     }
// //     cout<<ansnum<<endl;
// //    for(auto i:ans) cout<<i<<" ";
//     for(auto i:arr)
//     {
//         cout<<i.a.first<<" "<<i.a.second<<" "<<ans[i.index]<<endl;
//     }
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
    int n;
    cin>>n;
    vector<int> ans(n);
    vector<array<int,3>> arr(n);
    set<array<int,2>> st;
    int ansnum =0;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i][1]>>arr[i][0];
        arr[i][2] = i;
    }
    sort(arr.begin(),arr.end());
    for(int i =0;i<n;i++)
    {
        auto it = st.lower_bound({arr[i][1]});
        if(it!=st.begin())
        {
            it--;
            ans[arr[i][2]] = (*it)[1];
            st.erase(it);
        }
        else{
            ans[arr[i][2]] = st.size();
            st.insert({arr[i][0],ans[arr[i][2]]});
        }
        ansnum = max(ansnum,ans[arr[i][2]]);
    }
    cout<<ansnum+1<<endl;
    for(auto i:ans) cout<<i+1<<" ";
//dusro ka code copy karne se khar nahi chalta bhai
}