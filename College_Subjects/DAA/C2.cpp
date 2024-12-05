// Problem Statement No.08
// Implement subset problem
// Statement: Given a set of non-negative integers and a value sum,
// The task is to check if there is a subset of the given set whose sum is equal to the given sum

// Input: set[] = {3, 34, 4, 12, 5, 2} sum = 9
// Output: = True

#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumRec(vector<int> &arr, int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (arr[n - 1] > sum)
    {
        return isSubsetSumRec(arr, n - 1, sum);
    }

    return isSubsetSumRec(arr, n - 1, sum) || isSubsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    return isSubsetSumRec(arr, arr.size(), sum);
}

int main()
{
    vector<int> arr;
    int sum, num, temp;
    cout << "Enter the number of array elements" << endl;
    cin >> num;
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Enter the sum you are searching for" << endl;
    cin >> sum;

    if (isSubsetSum(arr, sum))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
