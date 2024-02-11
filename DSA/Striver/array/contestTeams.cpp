#include<iostream>
#include<vector>
using namespace std;
int merge(int i,int mid,int j,vector<int> &arr)
{

    int ans =0;
    int low =i,right =mid+1;
    for (int i = low; i <= mid; i++) {
        while (right <= j && arr[i] > 2 * arr[right]) right++;
        ans += (right - (mid + 1));
    }
    
    vector<int> a,b;
    for(int k =i;k<=mid;k++) a.push_back(arr[k]);
    for(int k =mid+1;k<=j;k++) b.push_back(arr[k]);

    int p1 =0,p2 =0;
    while(p1<a.size() and p2<b.size())
    {
        if(a[p1]>(b[p2]))
        {
            arr[i] = b[p2];
            p2++;i++;
           // ans += a.size()-p1;
        }
        else{
            arr[i] = a[p1];
            p1++,i++;
        }
    }
    while(p1<a.size())
    {
        arr[i] = a[p1];
        p1++,i++;
    }
    while(p2<b.size())
    {
        arr[i] = b[p2];
        p2++,i++;
    }    
    return ans;
}
int mergesort(int i,int j,vector<int> &arr)
{
    if(i>=j) return 0;
    int mid = (i+j)/2;
    int a = mergesort(i,mid,arr);
    int b = mergesort(mid+1,j,arr);
    int c = merge(i,mid,j,arr);
    return (a+b+c);
}
int team(vector <int> & vec, int n)
{
    int ans = mergesort(0,vec.size()-1,vec);
    return ans;
}
