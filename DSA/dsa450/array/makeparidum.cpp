#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int palindrome(vector<int> a)
{
    int step = 0;
    int low = 0;
    int high = a.size() - 1;
    while (low < high)
    {
        if (a[low] == a[high])
        {
            low++;
            high--;
        }
        else
        {
            if (a[low] > a[high])
            {
                a[high - 1] += a[high];
                high--;
                step++;
            }
            else
            {
                a[low + 1] += a[low];
                low++;
                step++;
            }
        }
    }
    return step;
}
int main()
{
    vector<int> arr = {2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1};
    int ans = palindrome(arr);
    cout << ans;
}