#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll vec[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputvecll(ll *vec,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         vec[i] = temp;
//     }
// }

int merge(int i,int mid,int j,vector<int> &vec)
{
    
    vector<int> a,b;
    for(int k =i;k<=mid;k++) a.push_back(vec[k]);
    for(int k =mid+1;k<=j;k++) b.push_back(vec[k]);

    int p1 =0,p2 =0;
    int ans =0;
    while(p1<a.size() and p2<b.size())
    {
        if(a[p1]>b[p2])
        {
            vec[i] = b[p2];
            p2++;i++;
            ans += a.size()-p1;
        }
        else{
            vec[i] = a[p1];
            p1++,i++;
        }
    }
    while(p1<a.size())
    {
        vec[i] = a[p1];
        p1++,i++;
    }
    while(p2<b.size())
    {
        vec[i] = b[p2];
        p2++,i++;
    }
    return ans;
}
int mergesort(int i,int j,vector<int> &vec)
{
    if(i>=j) return 0;
    int mid = (i+j)/2;
    int a = mergesort(i,mid,vec);
    int b = mergesort(mid+1,j,vec);
    int c = merge(i,mid,j,vec);
    return a+b+c;
}
int main()
{
test
{
    vector<int> vec;
    int n;
    cin>>n;
      int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
        vec.push_back(temp);
    }
    int ans=0;
    int mini = vec[0];
    for(int i =1;i<n;i++)
    {
        if(arr[i]<mini) ans++;
        mini = max(mini,vec[i]);
    }
    cout<<ans<<endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}