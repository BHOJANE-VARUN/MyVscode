#include "algorithm"
using namespace std;
string isPairDifferenceK(vector<int>arr, int n, int k) {
   int ind = 1;
   for(auto i:arr)
   {
       int ele = k+i;
       if(binary_search(arr.begin()+ind,arr.end(),ele))
       {
           return "Yes";
       }
       ind++;
   }
   return "No";
}
