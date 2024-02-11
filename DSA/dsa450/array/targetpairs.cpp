#include <iostream>
using namespace std;
int pairSum(int arr[], int n, int target)
{
    int count = 0;
    if (target > arr[n - 1])
    {
        for (int j = n - 1; j > 0; j--)
        {
            for (int i = 0; i < j; i++)
            {
                if (arr[j] + arr[i] == target)
                {
                    count++;
                }
                else if (arr[j] + arr[i] > target)
                {
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (arr[j] + arr[i] == target)
                {
                    count++;
                }
                else if (arr[j] + arr[i] < target)
                {
                    break;
                }
            }
        }
    }
    return count;
}
int main()
{
    int t = 6;
    int n =5;
    int arr[10]={1,2,3,4,5};
    int a = pairSum(arr,n,t);
    cout<<a;
}