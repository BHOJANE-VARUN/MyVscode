#include<iostream>
#include<vector>
using namespace std;
void merge(int i,int mid,int j,vector<int> &arr)
{
    
    vector<int> a,b;
    for(int k =i;k<=mid;k++) a.push_back(arr[k]);
    for(int k =mid+1;k<=j;k++) b.push_back(arr[k]);

    int p1 =0,p2 =0;
    while(p1<a.size() and p2<b.size())
    {
        if(a[p1]<b[p2])
        {
            arr[i] = a[p1];
            p1++;i++;
        }
        else{
            arr[i] = b[p2];
            p2++,i++;
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
    
}
void mergesort(int i,int j,vector<int> &arr)
{
    if(i>=j) return;
    int mid = (i+j)/2;
    mergesort(i,mid,arr);
    mergesort(mid+1,j,arr);
    merge(i,mid,j,arr);
}
int main()
{
    vector<int> vec = {53,5,2,6,9};
    mergesort(0,vec.size()-1,vec);
    for(auto i:vec) cout<<i<<" ";
    cout<<endl;
}