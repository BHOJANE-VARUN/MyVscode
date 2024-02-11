#include <bits/stdc++.h> 
using namespace std;
int minSwaps(vector<int> &arr)
{   
    int ans =0;
	for(int i =0;i<arr.size()-1;i++)
    {   
        int min = arr[i];
        int j = i+1,ind = -1;
        while (j<arr.size())
        {
            if(arr[j]<min)ind = j,min = arr[j];
            j++;
        }
        if(ind!=-1)ans++,swap(arr[i],arr[ind]);
        
    }
    return ans;
}
int main()
{
    vector<int> ve = {9,1,8,4};
    cout<<minSwaps(ve);
}