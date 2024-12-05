// Problem Statement No. 12
// Implement program to print all subsets of a given Set or Array.
// Statement: Given a set of positive integers, find all its subsets.


#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
{
    // Add the current subset to the result list
    res.push_back(subset);

    // Generate subsets by recursively including and excluding elements
    for (int i = index; i < A.size(); i++)
    {
        // Include the current element in the subset
        subset.push_back(A[i]);

        // Recursively generate subsets with the current element included
        calcSubset(A, res, subset, i + 1);

        // Exclude the current element from the subset (backtracking)
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<int> subset;
    // It is a vector of vectors that store the genrated subsets 
    vector<vector<int>> res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

// Driver code
int main()
{
    vector<int> array;
    int n, temp;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    vector<vector<int>> res = subsets(array);

    // Print the generated subset
    cout << "Possible subest of the given set are:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
