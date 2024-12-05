// Problem Statement No.10
// Implement program to find all distinct subsets of a given set using Bit Masking Approach.
// Statement: Given an array of integers arr[]. The task is to find all its subsets.
// The subset cannot conatin ducplicate elements

// Input S = {1, 2, 2}
// Output {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
/*
[10]
[10,12]
[10,12,12]
[10,12] this is not allowed
[12]
[12,12]
[12] this is not allowed
*/
void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ansList)
{
    ansList.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
        {
            continue;
        }

        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ansList);
        ds.pop_back();
    }
}

vector<vector<int>> AllSubsets(int arr[], int n)
{
    vector<int> nums(arr, arr + n);
    vector<int> ds;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ansList;
    findSubsets(0, nums, ds, ansList);
    return ansList;
}
void BitSubsets(int arr[],int n)
{
    set<vector<int>> ans;
    int cnt = (1 << n);
    for(int i =0;i<cnt;i++)
    {
        vector<int> temp;
        for(int j =0;j<n;j++)
        {
            if(i&(1<<j))
            {
                temp.push_back(arr[j]);
            }
        }
        ans.insert(temp);
    }   
    for (auto subset : ans)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "], "<<endl;
    }
}
int main()
{
    int set[] = {10, 12, 14};
    // vector<vector<int>> subsets = AllSubsets(set, 3);
    // for (auto subset : subsets)
    // {
    //     cout << "[";
    //     for (int i = 0; i < subset.size(); i++)
    //     {
    //         cout << subset[i];
    //         if (i < subset.size() - 1)
    //         {
    //             cout << ", ";
    //         }
    //     }
    //     cout << "], "<<endl;
    // }
    BitSubsets(set,3);
    return 0;
}
