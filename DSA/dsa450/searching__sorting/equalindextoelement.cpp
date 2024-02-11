#include <bits/stdc++.h> 
using namespace std;
vector<int> valueEqualToIndices(vector<int>& numArray, int n) {
	vector<int> ans;
	for(int i =0;i<n;i++)
	{
		if(i==numArray[i])ans.push_back(i);
	}
	if(ans.size()==0)ans.push_back(-1);
	return ans;
}
int main()
{
    vector<int> ve = {-1,0,2,4};
    vector<int> ans = valueEqualToIndices(ve,ve.size());
    for(auto i:ans)cout<<i;
}