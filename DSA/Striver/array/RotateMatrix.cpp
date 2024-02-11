#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &arr, int n, int m)
{
    int r1 =0,r2 = n-1;
    int c1 = 0,c2 = m-1;
    while(r1<r2 and c1<c2)
    {
        int last = arr[r1][c1];
        for(int i =c1+1;i<=c2;i++)
        {
            int temp = arr[r1][i];
            arr[r1][i] = last;
            last = temp;
        }
        for(int i =r1+1;i<=r2;i++)
        {
            int temp = arr[i][c2];
            arr[i][c2] = last;
            last = temp;
        }
        for(int i =c2-1;i>=c1;i--)
        {
            int temp = arr[r2][i];
            arr[r2][i] = last;
            last = temp;
        }
        for(int i =r2-1;i>=r1;i--)
        {
            int temp = arr[i][c1];
            arr[i][c1] = last;
            last = temp;
        }
        r1++,c1++;
        r2--,c2--;
    }  
}
int main()
{
    return 0;
}