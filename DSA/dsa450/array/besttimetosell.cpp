#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &arr, int n)
{
    vector<int> ans;
    int counter = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i] - arr[i - 1];
        if (temp >= 0)
        {
            counter += temp;
            ans.push_back(counter);
        }
        else
        {
            counter = 0;
        }
    }
    int ans1 = 0, ans2 = 0;
    for (auto i : ans)
    {
        if (i >= ans1)
        {
            ans2 = ans1;
            ans1 = i;
        }
    }
    return ans1 + ans2;
}
int main()
{
    vector<int> vec = {4, 3, 2, 1, 0};
    int n = 5;
    int ans = maxProfit(vec, n);
    cout << ans;
}