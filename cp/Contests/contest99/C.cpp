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
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long temp;
        long long ans =0;
        int n;
        cin>>n;
        for(int i =0;i<n;i++)
        {
            cin>>temp;
            pq.push(temp);
            ans += temp;
        }
        for(int i =0;i<n;i++)
        {
            cout<<ans<<" ";
            ans -= pq.top();
            pq.pop();
        }
        cout<<endl;
    }

}
