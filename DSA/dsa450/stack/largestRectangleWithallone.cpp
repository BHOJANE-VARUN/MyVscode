#include "stack"
#include "limits.h"
vector<int> nextSmallerElement(vector<int> arr, int n)
{
    // Write your code here.
    stack<int> sk;
    sk.push(-1);
    vector<int> ans(n);
    for(int i =n-1;i>=0;i--)
    {   int ele = arr[i];
        while(sk.top()!=-1 && arr[sk.top()]>=ele && (!sk.empty()))
        {
            sk.pop();
        }
        ans[i] = sk.top();
        sk.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    // Write your code here.
    stack<int> sk;
    vector<int> ans(n);
    sk.push(-1);
    for(int i =0;i<n;i++)
    {   int ele = arr[i];
        while(sk.top()!=-1 && arr[sk.top()]>=ele && (!sk.empty()))
        {
            sk.pop();
        }
        ans[i] = sk.top();
        sk.push(i);
    }
    return ans;
}
int largestRectangle(vector < int > & heights) {
  // Write your code here.
  int n = heights.size();
  vector<int> next(n),prev(n);
  next = nextSmallerElement(heights, n);
  prev = prevSmallerElement(heights, n);
  int area = INT_MIN;
  for(int i =0;i<n;i++)
  {
    int h = heights[i];
    if(next[i]==-1)
    {
      next[i]=n;
    }
    int b = next[i]-prev[i]-1;
    int cur = h*b;
    area = max(area,cur);
  }
  return area;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	vector<int> heig(m,0);
	int area =INT_MIN;
	for(int i =0;i<n;i++)
	{	
		for(int col =0;col<m;col++)
		{
			if(mat[i][col]==0)
			{
				heig[col]=0;
			}
			else{
				heig[col] += mat[i][col];
			}
		}
		int cur = largestRectangle(heig);
		area = max(cur,area);
	}
	return area;
}