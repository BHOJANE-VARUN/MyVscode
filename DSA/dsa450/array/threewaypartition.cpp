#include <bits/stdc++.h> 
using namespace std;
vector<int> threeWayPartition(vector<int> &arr, int n, int a, int b)
{
    int low=0;

    int mid=0;

    int high=n-1;

    while(mid<=high)

    {

        if (arr[mid]<a)

        {

            swap(arr[low],arr[mid]);

            low++;

            mid++;

        }

        else if (arr[mid]>b)

        {

            swap(arr[mid],arr[high]);

            high--;

        }

        else {

            mid++;

        }

    }

    return arr;

}
int main()
{
    return 0;
}