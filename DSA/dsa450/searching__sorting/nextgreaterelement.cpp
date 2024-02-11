#include <bits/stdc++.h> 
using namespace std;
vector<int> nextGreaterElement(vector<int>& arr, int n)
{   vector<int> ans;
	int i = 0;
    while(i<n-1)
    {
        if(arr[i]<arr[i+1])
        {
            ans.push_back(arr[i+1]);
            i++;
        }
        else{
            int j =i+1;int flag =0;
            while(j<n)
            {   
                if(arr[j]>arr[i])
                {
                    ans.push_back(arr[j]);
                    i++;flag =1;
                    break;
                }
                else{
                    j++;
                }
            }
            if(!flag)ans.push_back(-1),i++;
        }
    }
    ans.push_back(-1);
    return ans;
}
int main()
{
    vector<int> test= {7,12,1,20};
    vector<int> ans = nextGreaterElement(test,test.size());
    for(auto i:ans)
    {
        cout<<i<<"  ";
    }
}