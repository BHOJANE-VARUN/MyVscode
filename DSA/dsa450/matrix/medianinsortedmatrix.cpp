#include <bits/stdc++.h> 
using namespace std;
int findMedian(vector<vector<int> > &arr, int n, int m){
    multiset<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans.insert(arr[i][j]);
        }
        
    }
    int count=0;
    for (auto i:ans)
    {
        if(count==((m*n)/2))
        {
            return i;
        }
        count++;
    }
    
    
}
int main()
{
    vector<vector<int>> test = {{1, 3, 5},{2, 6, 9},{3, 6 ,9}};
    int ans = findMedian(test,3,3);
    cout << ans;
}