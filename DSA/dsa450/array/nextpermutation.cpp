#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mergeIntervals(vector<int> &arr, int n)
{
    if (n < 2)
    {
        return arr;
    }
    int k = 0;
    int t = n-1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[t] > arr[i])
        {
            int temp = arr[t];
            for (int j = t; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = temp;
            k++;
            break;
        }
        else{
        t--;
    }
    }
    
    if (k == 0)
    {
        sort(arr.begin(), arr.end());
        return arr;
    }
    return arr;
}
int main(){
int n =5;
vector<int> vec = {1,5,3,4,2};
mergeIntervals(vec,n);
for (int i = 0; i < vec.size(); i++)
{
    cout<<vec[i]<<endl;
    
}


}
