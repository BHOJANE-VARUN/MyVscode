#include <bits/stdc++.h>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> vec;
    int i=0,j=0;
    while (i<m && j<n)
    {
        if(arr1[i]>arr2[j])vec.push_back(arr2[j]),j++;
        else vec.push_back(arr1[i]),i++;
    }
    if(j<n)
    {
        while (j<n)
        {
            vec.push_back(arr2[j]);j++;
        }    
    }
    if(i<m)
    {
        while (i<m)
        {
            vec.push_back(arr1[i]);i++;
        }
        
    }
    return vec;
}