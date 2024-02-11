#include <bits/stdc++.h> 
using namespace std;
int kMinFloor(vector<vector<int>> &squareCity, int n, int k) {
	multiset<int> ans;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			ans.insert(squareCity[j][i]);
		}
	}
	int count =0;
	for(auto i:ans)
	{
		if(count==(k-1))
		{
            return i;
		}
		count++;
	}
	return a;
}
int main()
{
    return 0;
}