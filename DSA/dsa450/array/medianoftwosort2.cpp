#include <bits/stdc++.h>
using namespace std;
double median(vector<int>& a, vector<int>& b) {
    int cur = 0;
    int ans =0;
    int tar = 0;
    int i =0,j =0;
    int size = a.size()+b.size();
    int index = (size/2);
    while (ans!=index)
    {
       if (a[i]>b[j])
       {
        ans = i+j+1;
        cur = a[i];
        tar = max(tar,b[j]);
        j++;
        if(j>=b.size())
         {
            break;
         }
        
         if (b[j]==b[j+1])
        {
            ans++;
            tar = b[j];
            cur = b[j];
            j++;
        }
        if (a[i]==a[i+1])
        {
            ans++;
            tar = a[i];
            i++;
        }
       }

       else
       {
        ans = i+j+1;
        cur = b[j];
        tar = max(tar,a[i]);
         i++;
         if(i>=a.size())
         {
            break;
         }
         if (a[i]==a[i+1])
        {
            ans++;
            tar = a[i];
            cur = a[i];
            i++;
        }
        if (b[j]==b[j+1])
        {
            ans++;
            tar = b[j];
            j++;
        }
       }
       
       
    }
   if (size%2==0)
    {
        return (tar+cur)/2.0;
    }
    else{
        return cur;
    } 
}
int main()
{  /* 1 2 2
2 4 4  */
    vector<int> arr1 = {1,2,2};
    vector<int> arr2 = {2,4,4};
    double ans = median(arr1,arr2);
    cout<<ans;
}