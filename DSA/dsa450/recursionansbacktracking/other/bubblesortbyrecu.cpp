#include<iostream>
#include<vector>
using namespace std;
void sortarray(vector<int> &arr,int high)
{   if(high<2)return;


    for(int i =1;i<high;i++)
    {
        if(arr[i-1]>arr[i])
        {
            swap(arr[i-1],arr[i]);
        }
    }
    sortarray(arr,--high);
}
int main()
{
    vector<int> arr = {5,4,3,2,1};
    sortarray(arr,arr.size());
    for(auto i:arr)
    {
        cout<<i<<"  ";
    }
}