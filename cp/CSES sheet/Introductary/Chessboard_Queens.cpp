#include<bits/stdc++.h>
#define int long long int
#define Y "YES"
#define N "NO"
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
int ans =0;
vector<vector<bool>> arr(8,vector<bool> (8,1));
vector<bool> column(8,1),first(16,1),second(16,1);
void solve(int row)
{
    if(row==8)
    {
        ans++;
        return;
    }
    for(int col =0;col<8;col++)
    {
        int diagonal1 = row+col;
        int diagonal2 = row-col+7;
        if(arr[row][col] and column[col] and first[diagonal1] and second[diagonal2])
        {
            arr[row][col] =0;
            column[col] =0;
            first[diagonal1]=0;
            second[diagonal2]=0;
            solve(row+1);
            arr[row][col] =1;
            column[col] =1;
            first[diagonal1]=1;
            second[diagonal2]=1;
        }
    }
    return;
}
signed main()
{
    for (int  i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char temp;
            cin>>temp;
            if(temp=='.')
            arr[i][j]=true;
            else arr[i][j]=false;
        }
        
    }
    
    solve(0);
    cout<<ans<<endl;
//dusro ka code copy karne se khar nahi chalta bhai
}