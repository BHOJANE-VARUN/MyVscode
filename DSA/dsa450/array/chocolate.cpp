#include <bits/stdc++.h>
using namespace std;
int findMinDiff(int n, int m, vector<int> chocolates) {
    // Write your code here.
    sort(chocolates.begin(),chocolates.end());
    int ans =INT_MAX;
    for(int i =m-1;i<n;i++)
    {   int temp = chocolates[i]-chocolates[i-m+1];
        ans = min(ans,temp);
    }

return ans;

}
int main()
{
    vector<int> ar = {2,5,4};
    int n = ar.size();
    int ans = findMinDiff(n,2,ar);
    cout<<ans;
}