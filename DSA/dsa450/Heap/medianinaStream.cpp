#include "queue"
int signum(int a,int b)
{
	if(a==b)
	{
		return 0;
	}
	else if(a>b)
	{
		return 1;
	}
	else return -1;
}
void cal(int ele,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int &mid)
{
	switch(signum(maxi.size(),mini.size()))
	{
		case 0:
		if(ele>mid)
		{
			mini.push(ele);
			mid = mini.top();
		}
		else{
			maxi.push(ele);
			mid = maxi.top();
		}
		break;
		case 1:
		if(ele>mid)
		{
			mini.push(ele);
		}
		else{
			mini.push(maxi.top());
			maxi.pop();
			maxi.push(ele);
		}
		mid = (mini.top()+maxi.top())/2;
		break;
		case -1:
		if(ele>mid)
		{
			maxi.push(mini.top());
			mini.pop();
			mini.push(ele);
			mid = (mini.top()+maxi.top())/2;
		}
		else{
			maxi.push(ele);
			mid = (mini.top()+maxi.top())/2;
		}
		break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxheap;
	priority_queue<int,vector<int>,greater<int>> minheap;
    vector<int> ans;
	int mid = 0;
	for(int i =0;i<n;i++)
	{	
		cal(arr[i],maxheap,minheap,mid);
		ans.push_back(mid);
	}
	return ans;
}
