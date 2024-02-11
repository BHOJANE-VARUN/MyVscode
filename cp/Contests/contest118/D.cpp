#include <bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
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
    test
    {
        int n, k;
        cin >> n >> k;
        int low = 1;
        int high = n;
        int mid = (high + low) / 2;
        while (low <= high)
        {
            int key = mid*k;
            if ((key)==n)
            {
                break;
            }
            else if (key > n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = (high + low) / 2;
        }
        for(int i =1;i<=k;i++)
        {
            cout<<mid*i<<" ";
        }
        cout<<endl;
    }
    // dusro ka code copy karne se khar nahi chalta bhai
}