#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int actualsum = 0;
	int xr =0;
	for(int i =0;i<n;i++)
	{
		xr = xr^(i+1);
		xr = xr ^ arr[i];
		actualsum += arr[i];
	}
	// 5 0 23  
	//cout<<numxr<<" "<<actualor<<" "<<actualsum<<endl;
	//5
	//cout<<findxr<<"	";
	//5
	int findnum = (xr & ~(xr-1));
	//cout<<sum;
	int one =0,zero =0;
	for(int i =0;i<n;i++)
	{
		if((arr[i] & findnum)==0)
		{
			zero = zero^arr[i];
		}
		else{
			one = one^arr[i];
		}
	}
	for(int i =1;i<=n;i++)
	{
		if((i & findnum)==0)
		{
			zero = zero^i;
		}
		else{
			one = one^i;
		}	
	}
	// 
	//cout<<ans.first<<" "<<ans.second;
	pair<int,int> actualans;
	int expsum = ((n*(n+1))/2);
	if(expsum<actualsum)
	{
		actualans.first = min(one,zero);
		actualans.second = max(one,zero);
	}
	else{
		actualans.second = min(one,zero);
		actualans.first = max(one,zero);
	}
	return actualans;
}
