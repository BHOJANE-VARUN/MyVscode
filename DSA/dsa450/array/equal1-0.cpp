#include <bits/stdc++.h>
using namespace std;
int findSubarray(vector<int> arr)
{   int z=0;
    int on=0;
    int n = arr.size();
    int ans =INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            on++;
        }
        else{
            z++;
        }
        if(on==z)
        {
            ans = max(ans,i+2);
        }
    }
     z=0;
     on=0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==1)
        {
            on++;
        }
        else{
            z++;
        }
        if(on==z)
        {
            ans = max(ans,(n-1-i)+1);
        }
    }
    return ans;
}
int main()
{
    vector<int> tet = {0, 0, 1 ,0 ,1 };
    int ans = findSubarray(tet);
    cout<<ans;
}