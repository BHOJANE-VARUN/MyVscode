#include <bits/stdc++.h>
class heap{
    /*
    node = i
    left child = 2*i
    right child = 2*i +1
    parent = (i/2)
    */
    public:
    int size =0;
    void insert(int ele,vector<int> &vec)
    {
        size++;
        int index = size;
        vec[index] = ele;

        while(index>1)
        {
            int parent = index/2;

            if(vec[parent] > vec[index])
            {
                swap(vec[parent],vec[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deletion()
    {
        if(size==0)
        {
            return;
        }
        arr[1]=arr[size];
        size--;

        int i =1;
        while(i<size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i+1;
            if(leftindex<size && arr[i]>arr[leftindex])
            {
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex<size && arr[i]>arr[rightindex])
            {
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }
    }
    
}; 
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    vector<int> ans(arr.size()+1);
    ans[0]=-1;
    heap obj;
    for(auto i:arr)
    {
        obj.insert(i,ans);
    }
    vector<int> vec;
    for(int i = 1;i<ans.size();i++)
    {
        vec.push_back(ans[i]);
    }
    return vec;
}
