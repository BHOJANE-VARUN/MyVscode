#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int i = 0, ans = 0, j = 0;
    while (i<n)
    {
        if (ans < k)
        {
            ans += arr[i++];
        }
        else if (ans > k)
        {
            ans -= arr[j++];
        }
        if(ans == k)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> vec = {8, 59, 58, 79, 44, 7, 65, 69, 60 ,51 };
    int n = 10;
    int k = 172;
    bool r = subsetSumToK(n, k, vec);
    cout << r << endl;
}