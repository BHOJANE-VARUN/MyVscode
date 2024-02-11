#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> subset(vector<int> arr)
{
    vector<vector<int>> ans;
    vector<int> one;
    ans.push_back(one);
    for (int i = 0; i < arr.size(); i++)
    {
        int n = ans.size();
        for (int j = 0; j < n; j++)
        {
            vector<int> temp = ans.at(i);
            temp.push_back(arr[i]);
            ans.push_back(temp);
        }
        
    }
    return ans;
    
}
int main()
{
    
}