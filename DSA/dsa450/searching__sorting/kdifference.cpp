#include "algorithm"
#include<iostream>
string isPairDifferenceK(vector<int>arr, int n, int k) {
   int ind = 1;
   for(auto i:arr)
   {
       int ele = k+i;
       if(ele>arr[n-1])return "No";
       if(binary_search(arr.begin()+ind,arr.end(),ele))
       {
           return "Yes";
       }
       ind++;
   }
   return "No";
}
