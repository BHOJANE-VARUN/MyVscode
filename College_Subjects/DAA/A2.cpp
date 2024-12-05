// Problem Statement No.02
// Implement a problem of move all the zeroes to end of the array.
// Given an array of random numbers, Push all the 0s of a given array to the end of the array. The order of the elements should be same.
// Input: arr[] = {1,2,0,4,3,0,5,0}
// Output: arr[] = {1,2,4,3,5,0,0,0}

#include <iostream>
using namespace std;
int main()
{
    int n;
    int j = 0;
    cout << "Enter the number of array elements" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // j increases only when it encounters on zero element
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}