#include <bits/stdc++.h> 
using namespace std;
int minimumSwaps(vector<int> &arr, int n, int k)
{   
    int in =0,out =0;
    int ans ;
    for(auto i:arr)
    {
      if (i <= k) {
        in++;
      };
    }
    ans = in;
	for(int i =0;i<in;i++)
	{
		if(arr[i]>k)
		{
			out++;
		}
        else
        {
            ans--;
        }
        
	}
    for (int i = in; i < n; i++)
    {	
		if(arr[i]>k)
		{
			out++;
		}
		if(arr[i-in]>k)
		{
			out--;
		}
       ans = min(out,ans); 
    }
   return ans==1000?0:ans; 
}
int main()
{   //7 4
  //1 1 3 3 5 7 7
    int n =7;
    int k = 4;
    vector<int> arr = {1,1,3,3,5,7,7};
    int ans = minimumSwaps(arr,n,k); 
    cout<<ans;
}
