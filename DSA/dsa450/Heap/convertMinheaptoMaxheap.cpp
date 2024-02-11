void heapify(int index,vector<int> &ans,int n)
{
    int large = index;
    int left = 2*large+1;
    int right = 2*large+2;

    if(left<n and ans[left]>ans[large])
    {
        large = left;
    }
    if(right<n and ans[right]>ans[large])
    {
        large = right;
    }
    if(large!=index)
    {
        swap(ans[large],ans[index]);
        heapify(large,ans,n);
    }
}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	for(int i = n/2;i>=0;i--)
	{
		heapify(i,arr,n);
	}
	return arr;
}