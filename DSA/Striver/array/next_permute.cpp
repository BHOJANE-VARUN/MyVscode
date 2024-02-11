#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &arr) {
    // Write your code here.
    int n=arr.size();
    int index=-1;

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index=i;
            break;
        }
    }

    if(index==-1){
    reverse(arr.begin(),arr.end());
    return arr;
    }

    for(int i=n-1;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}
int main()
{
    vector<int> vec = {6,10,8,13,13};
    vec = nextGreaterPermutation(vec);
    for(auto i:vec) cout<<i<<" ";
}