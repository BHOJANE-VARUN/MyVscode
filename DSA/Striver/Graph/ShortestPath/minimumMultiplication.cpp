#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        int num = 1e5;
        vector<int> ans(num, INT_MAX);
        pq.emplace(0, start);
        ans[start] =0;
        while (!pq.empty())
        {
            //auto[cnt, ele] = pq.top();
            int cnt = pq.top().first,ele = pq.top().second;
            pq.pop();
            for (int i = 0; i < arr.size(); i++)
            {
                int nexele = (ele*arr[i])%num;
                if(cnt+1<ans[nexele])
                {
                    ans[nexele] = cnt+1;
                    pq.emplace(cnt+1,nexele);
                }
            }
        }
        return ans[end];
    }
};
signed main()
{
    test
    {
    }
    // dusro ka code copy karne se ghar nahi chalta bhai
}