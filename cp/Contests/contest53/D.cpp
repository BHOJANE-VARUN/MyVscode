#include <bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
// const int maxsize = 1e5;
// ll arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
void inputarrll(ll *arr, ll n)
{
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
}
int main()
{
    test
    {
        ll n;
        cin >> n;
        ll *arr = new ll[n];
        inputarrll(arr, n);
        int zeroct = 0, onect = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == arr[i])
            {
                if (arr[i] == 0)
                    zeroct++;
                else
                    onect++;
            }
            if (i == n - 1)
            {
                if (arr[i] == arr[0])
                {
                    if (arr[i] == 0)
                        zeroct++;
                    else
                        onect++;
                }
            }
        }
        int ans = min(zeroct,onect);
        if(ans%2) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    
    // dusro ka code copy karne se khar nahi chalta bhai
}