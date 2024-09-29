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
signed main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> arr;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
        arr.push_back(mp.size());
        auto it = lower_bound(arr.begin(), arr.end(),arr[arr.size()-1] - k+1);
        cout<<mp.size()-k+1<<" "<<(it-arr.begin())<<" "<< arr.size()<<endl;
        if (it != arr.end())
        {
            int index = it - arr.begin();
            ans += i - index + 1;
        }
    }
    for(auto i:arr) cout<<i<<' ';
    cout<<endl;
    cout << ans << endl;

    // dusro ka code copy karne se ghar nahi chalta bhai
}