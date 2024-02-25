#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
signed main()
{
test
{
    
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int xo = 0, ans = 0;
	for (int i = 0; i <= n - k; i++)xo ^= (s[i] - '0');
	if (xo == 1)ans++;

	int beg = 0, end = n - k + 1;
	while (end < n) {
		xo ^= (s[beg++] - '0');
		xo ^= (s[end++] - '0');

		if (xo == 1)ans++;
	}

	cout << ans << endl;
}
//dusro ka code copy karne se khar nahi chalta bhai
}