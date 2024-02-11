#include <bits/stdc++.h>
using namespace std;
// int binarySearch(vector<int> arr, int l, int r, int x)
// {
//     while (l <= r)
//     {
//         int m = l + (r - l) / 2;

//         // Check if x is present at mid
//         if (arr[m] == x)
//             return m;

//         // If x greater, ignore left half
//         if (arr[m] < x)
//             l = m + 1;

//         // If x is smaller, ignore right half
//         else
//             r = m - 1;
//     }

//     // If we reach here, then element was not present
//     return -1;
// }
pair<int, int> search(vector<vector<int>> arr, int x)
{
    int n = arr.size();
    int i = 0;
    pair<int, int> ans = {-1, -1};
    while (i < n)
    {
        if (arr[i][0] > x || arr[i][n - 1] < x)
        {
            i++;
            continue;
        }
        else
        {
            int l = 0;
            int r = n - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;

                // Check if x is present at mid
                if (arr[i][m] == x)
                {
                    ans = {i, m};
                    break;
                }

                // If x greater, ignore left half
                if (arr[i][m] < x)
                    l = m + 1;

                // If x is smaller, ignore right half
                else
                    r = m - 1;
            }
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> test = {{1, 2, 5}, {3, 4, 9}, {6, 7, 10}};
    pair<int, int> ans = search(test, 4);
    cout << ans.first << "  " << ans.second;
}