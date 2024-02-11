#include <bits/stdc++.h>
using namespace std;
int waterdripping(vector<int> &arr, int n)
{
    int max = 1, temp = 0, ans = 0, first = 0;
    int presum = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[first] <= arr[i])
        {
            ans += arr[first] * (i - (first + 1)) - temp;
            temp = 0;
            first = i;
            max = i +1;
            presum =0;
        }
        else if (i == n - 1 && arr[max] < arr[i])
        {
            ans += arr[i] * (i - (first + 1)) - temp;
        }

        else if (i == n - 1)
        {
            
            
            temp = temp - presum;
            ans += arr[max] * (max - (first + 1)) - presum;
            if (max == first+1 || max+1 == i)
            {
                return ans;
            }
            ans += arr[i] * (i - (max + 1)) - temp;
        }
        else
        {
            if (arr[i] >= arr[max])
            {
                max = i;
                presum = temp;
            }
            temp += arr[i];
        }
    }
    return ans;
}
int main()
{
    int n = 11;
    vector<int> vec = {10 ,11, 13, 8 ,5 ,14 ,9 ,3 ,11 ,11, 9 };
    int ans = waterdripping(vec, n);
    cout << ans;
}