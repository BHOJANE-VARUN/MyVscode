#include <bits/stdc++.h>
using namespace std;
int waterdripping(vector<int> &arr, int n)
{
    int ans =0;
    int div = 0;
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>=arr[max])
        {
            ans += arr[max]*(i-(max+1))-div;
            max = i;
            div =0;
        }
        else if()
        else{
            div += arr[i];
        }
        
    }
    
}
