#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
void inputarrint(int *arr,int n)
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
       arr[i] = temp;
    }
}
signed main()
{
test
{

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> days(n);
        for (int i = 0; i < n; i++) {
            cin >> days[i];
        }

        int result = INT_MAX;
        for (int i = 0; i < n; i++)
            days[i] %= 3;

        vector<vector<int>> arri = {{1, 1, 1}, {2, 2, 2}, {0, 0, 0}, {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

        for (int index = 0; index < 9; index++) {
            int count = 0;
            for (int i = 0; i < n; i++)
                count += (3 + arri[index][i % 3] - days[i]) % 3;
            result = min(count, result);
        }

        cout << result << endl;

}
}
//dusro ka code copy karne se khar nahi chalta bhai
}