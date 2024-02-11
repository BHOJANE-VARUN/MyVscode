#include <bits/stdc++.h> 
using namespace std;
int givesetbits(int x)
{
    int count =0;
    while(x!=0)
    {
        x = x&(x-1);
        count++;
    }
    return count++;
}
void sortSetBitsCount(vector<int>& arr, int size)
{
    multimap<int,int,greater<int>>map;
    for(int i=0;i<size;i++)
    {
        map.insert({givesetbits(arr[i]),arr[i]});
    }
    int i =0;
    for(auto j:map)
    {
        arr[i]=j.second;
        i++;
    }
    
}
int main()
{
    vector<int> vec = {4 ,3, 8};
    int size = vec.size();
    sortSetBitsCount(vec,size);
    for(auto i:vec)cout<<i<<"  ";  
}