#include<bits/stdc++.h>
typedef long long int ll;
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//ll arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
// void inputarrll(ll *arr,ll n)
// {   ll temp;
//     for(ll i =0;i<n;i++)
//     {
//         cin>>temp;
//         arr[i] = temp;
//     }
// }
int main()
{
    test
    {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "1 2 3" << endl;
		continue;
	}
	if (n == 4) {
		cout << "3 2 1 4" << endl;
		continue;
	}	
	vector<int> a(n);
	a[0] = n;
	a[1] = n - 2;
	a[n - 1] = n - 1;
	a[n - 2] = n - 3;
	for (int i = 2; i < n - 2; ++i) {
		a[i] = i - 1;
	}
	for (auto aa: a) {
		cout << aa << " ";
	}
	cout << endl;
    }

//dusro ka code copy karne se khar nahi chalta bhai
}