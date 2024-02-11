#include <bits/stdc++.h>
using namespace std;
double median(vector<int>& a, vector<int>& b) {
	for(auto i:b)
	{
		a.push_back(i);
	}
	int index = a.size()/2;
	sort(a.begin(),a.end());
	if((a.size())%2==1)
	{
		return a[index];
	}
	else{
		return ((a[index]+a[index-1])/2.0);
	}
}
int main()
{  /* 3 3
    2 4 6 
    1 3 5 */
    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {1,3,5};
    double ans = median(arr1,arr2);
    cout<<ans;
}