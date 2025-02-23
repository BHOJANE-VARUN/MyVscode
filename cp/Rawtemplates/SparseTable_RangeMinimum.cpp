// video https://youtu.be/0jWeUdxrGm4
// problem https://www.spoj.com/problems/RMQSQ/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
	// 1) read input
	int n;
	cin >> n;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
	// 3) answer queries
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << query(L, R) << "\n";
	}
}






// maximum range query


#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> lookup;
// don't forget to clear lookup table after each query
//  lookup.clear();
void buildSparseTable(int arr[], int n)
{
	lookup.resize(n, vector<int>(log2(n) + 1, 0));
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    for (int j = 1; (1 << j) <= n; j++) {
 

        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
 
            if (lookup[i][j - 1] > lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 

int query(int L, int R)
{

    int j = (int)log2(R - L + 1);
 

    if (lookup[L][j] >= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}

int main()
{
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
 
    buildSparseTable(a, n);
 
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
	
    return 0;
}

