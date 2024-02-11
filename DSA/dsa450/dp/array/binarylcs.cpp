#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n){

  vector<int> ans;
  ans.push_back(arr[0]);
  for(int i=1;i<n;i++)
  {
        if(arr[i]>ans[ans.size()-1]) ans.push_back(arr[i]);
        else{
            int it = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[it] = arr[i];
        }
  }
  return ans.size();

}
int main()
{
    int arr[] = {5,4,11,1,16,8};
    cout<<longestIncreasingSubsequence(arr,6);
}