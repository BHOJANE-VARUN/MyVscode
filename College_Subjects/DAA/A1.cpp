// Problem Statement No.01
// Implement a problem of number of zeroes..
// Given an array of 1s and 0s which has all 1s first followed by all 0s. 
// Count the number of zeroes in the given array
// Input: arr[] = {1,1,1,1,0,0}     Output: 2
// Input: arr[] = {1,0,0,0,0}       Output: 4

#include <iostream>
using namespace std;

// funtion to check first occurence of zero
int firstZeroOccurrence(int arr[], int low, int high)
{
    if (high >= low)
    {
        // Check if the mid element is first 0
        // Calculate mid
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0)
        {
            return mid;
        }

        // If the mid element is not 0
        // Discard first part of the array
        // Check first 0 in the second part of the array
        if (arr[mid] == 1)
        {
            return firstZeroOccurrence(arr, (mid + 1), high);
        }
        // Discard second part of the array
        // Check for the first 0 int he first part of the array
        else
        {
            return firstZeroOccurrence(arr, low, (mid - 1));
        }
    }
    return -1;
}

// Function to count the number of 0s
int countTotalZeroes(int arr[], int n)
{
    // Index of the first 0 int array
    // Parameters low = 0, high = size-1
    int first = firstZeroOccurrence(arr, 0, n - 1);

    // If no 0 present return 0
    // The check funtion will retrun -1 if no 0 present
    if (first == -1)
    {
        return 0;
    }
    else
    {
        return (n - first);
    }
}

int main()
{
    int n;
    // Take input form the user
    cout << "Enter the number of elements in the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the count function
    cout << "The count of zeroes in the array is " << countTotalZeroes(arr, n) << endl;
    return 0;
}