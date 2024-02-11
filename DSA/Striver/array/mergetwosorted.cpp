#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void fixedit(vector<long long>&a)
{
    int i =0;
    while (i<a.size()-1 and a[i]>a[i+1])
    {
        swap(a[i],a[i+1]);
        i++;
    }
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int ptr1 =0;
    while (ptr1!=a.size())   
    {
        if(a[ptr1]>b[0])
        {
            swap(a[ptr1],b[0]);
            fixedit(b);
        }
        else{
            ptr1++;
        }
    }
}
int main()
{
    vector<long long> a = {1,2,3};
    vector<long long> b = {2,3,4,5};
    mergeTwoSortedArraysWithoutExtraSpace(a,b);
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    for(auto j:b) cout<<j<<" ";
}