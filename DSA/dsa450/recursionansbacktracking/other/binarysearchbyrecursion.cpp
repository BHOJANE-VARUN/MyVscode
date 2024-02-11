#include<iostream>
#include<vector>
using namespace std;
bool binary_search(vector<int>&vec,int high,int low,int ele)
{
    int mid = (high+low)/2;
    if(vec[mid]==ele)
    {
        return true;
    }
    if(high<low)return false;
    else if(mid>vec[low]) return binary_search(vec,high,mid+1,ele);
    else return binary_search(vec,mid-1,low,ele);
}
int main()
{
    vector<int> vec = {1000000000,200000000,300000000,50000000,600000000};
    cout<<binary_search(vec,vec.size()-1,0,100000);
}