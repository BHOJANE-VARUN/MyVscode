#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    //binary search on arr
    int s =0,e=n-1;
    int ans =arr[0]+arr[n-1];
    int j,i;
    while (s<e)
    {  
        if (arr[e]+arr[s]>k)
        {
            e--;
            j = e-1;
            i=j;
        }
        else if(arr[e]+arr[s]<k)
        {   if(i==0)
            {
                e--;
             j = e-1;
             i=j;
             continue;

            }
            if(ans<k){
            ans +=arr[i];
            i--;
            }
            else{
                ans -=arr[j];
                j--;
            }

        }
        if(ans==k){
            return true;
        }

        
    }
    return false;
    
}
int main()
{
    vector<int> vec = {8, 59, 58, 79, 44, 7, 65, 69, 60 ,51 };
    int n = 10;
    int k = 172;
    bool r = subsetSumToK(n, k, vec);
    cout << r << endl;
}