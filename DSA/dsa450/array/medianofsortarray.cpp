#include <bits/stdc++.h>
using namespace std;
vector<double> findMedian(vector<int> &arr, int n, int m)
{
    vector<double> ans;
    multiset<int> cont;
    int index = m / 2;

    for (int i = 0; i < m; i++)
    {
        cont.insert(arr[i]);
    }

    if (m % 2 == 0)
    {
        auto temp = cont.begin();
        for (int i = 0; i < index-1; i++)
        {
            temp++;
        }
        ans.push_back(((*temp) + (*(++temp))) / 2.0);
        for (int i = 1; i < n - m+1; i++)
        {
            cont.insert(arr[i + m - 1]);
            auto it = cont.find(arr[i - 1]);
            cont.erase(it);
            auto temp = cont.begin();
            for (int i = 0; i < index-1; i++)
            {
                temp++;
            }
            ans.push_back(((*temp) + (*(++temp))) / 2.0);
        }
    }
    else{
        auto temp = cont.begin();
        for (int i = 0; i < index; i++)
        {
            temp++;
        }
        ans.push_back(*temp);
        for (int i = 1; i < n - m+1; i++)
        {   
            cont.insert(arr[i + m - 1]);
            auto it = cont.find(arr[i - 1]);
            cont.erase(it);
            auto temp = cont.begin();
            for (int i = 0; i < index; i++)
            {
                temp++;
            }
            ans.push_back(*temp);
        }
    }
    return ans;
}
int main()
{
    // 4 3
    // 1 2 3 4
    int n = 8;
    int m = 3;
    vector<int> arr = {1, 2, 3, 4, 4, 3, 2, 1};
    vector<double> ans = findMedian(arr, n, m);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}