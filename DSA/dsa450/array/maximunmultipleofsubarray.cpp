#include <bits/stdc++.h>
using namespace std;
int MaxMulsubarray(vector<int> &arr,int n )
{   if(n<2)
  { 
      return arr[n-1];
  }
    int  neg=1,pos =1,posbest =0;
    for (int i = 0; i < arr.size(); i++)
    {
       if (arr[i]==0)
       {
        neg =1;
        pos = 1;
        continue;
       }
       else
       {
         int temp = neg;
         neg = min(neg*arr[i],pos*arr[i]);
         neg = min(neg,arr[i]);
         pos = max(temp*arr[i],pos*arr[i]);
         pos = max(pos,arr[i]);
         posbest = max(pos,posbest); 
       }
       
        
    }
 return posbest;   
}
int main()
{
    vector<int> vec = {3 ,5 ,-2, -4};
    int a =4;
    int ans = MaxMulsubarray(vec,a);
    cout<<ans<<endl;   
}