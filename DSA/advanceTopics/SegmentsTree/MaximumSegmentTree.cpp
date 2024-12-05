#include<bits/stdc++.h>
using namespace std;
int t[4*1000];
// 1 based indexing for accessing elements in t and 0 based for range
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
int maximum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(maximum(v*2, tl, tm, l, min(r, tm)) , maximum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
// now if there is some updation query ,such that arr[x] = y then
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
int main()
{
    int arr[] = {4,1,7,4,9,56,4,3,8};
    int n = 9;
    vector<pair<int,int>> queries = {{0,1},{3,6}};
    build(arr,1,0,n-1);
    for(auto i :queries)
    {
        cout<<maximum(1,0,n-1,i.first,i.second)<<endl;
    }
    update(1,0,n-1,1,333);
    cout<<maximum(1,0,n-1,0,0)<<endl;
}   