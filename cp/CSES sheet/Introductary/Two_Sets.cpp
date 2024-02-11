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
void inputarrint(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
}
signed main()
{
    {
        // 8*9=36  1,2,3,4,5,6,7,8 = 18
        int n;
        cin >> n;
        int sum = (n * (n + 1)) / 2;
        if (sum % 2)
        {
            cout << "NO" << endl;
            return 0;
        }
        cout << Y << endl;
        if (n == 3)
        {
            cout << 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << endl;
            cout << 3 << endl;
        }
        else if (n == 4)
        {
            cout << 2 << endl;
            cout << 3 << " " << 2 << endl;
            cout << 2 << endl;
            cout << 1 << " " << 4 << endl;
        }
        else if (n % 2 == 0)
        {
            
            int num = n / 4;
            int size1 = n / 2 + 1;
            int size2 = n / 2 - 1;
            int num2 = -1;
            if (num % 2)
            {
                num = n / 2;
                size1 = n / 2;
                size2 = size1;
                num2 = n / 4;
            }
            cout << size1 << endl;
            for (int i = 1; i <= n; i += 2)
            {
                if (num2 == i)
                    continue;
                cout << i << " ";
            }
            cout << num << endl;
            cout << size2 << endl;
            if (num2 != -1)
            {
                cout << num2 << " ";
            }
            for (int i = 2; i <= n; i += 2)
            {
                if (i == num)
                    continue;
                cout << i << " ";
            }
        }
        else
        {
            int tar = (n + 1) / 4;
            if (tar % 2 == 0)
            {
               
                cout << (n / 2 + 1) << endl;
                cout << tar - 1 << " " << tar + 1 << " ";
                for (int i = 2; i <= n; i += 2)
                {
                    if (i == tar)
                        continue;
                    cout << i << " ";
                }
                cout << endl;
                cout << (n / 2) << endl;
                cout << tar << " ";
                for (int i = 1; i <= n; i += 2)
                {
                    if (i == tar - 1 or i == tar + 1)
                        continue;
                    cout << i << " ";
                }
            }
            else{
                cout<<n/2<<endl;
                for(int i =1;i<=n;i+=2)
                {
                    if(i==tar) continue;
                    cout<<i<<" ";
                }
                cout<<endl;
                cout<<(n/2)+1<<endl;
                cout<<tar<<" ";
                for(int i =2;i<=n;i+=2)
                {
                    cout<<i<<" ";
                }
                
            }
        }
    }
    // dusro ka code copy karne se khar nahi chalta bhai
}