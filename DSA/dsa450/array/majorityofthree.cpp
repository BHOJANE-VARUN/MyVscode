#include <iostream>
#include <map>
#include<unordered_map>
#include<vector>
using namespace std;
int majoritythree(vector<int> &arr,int n,int k)
{
    int t = n/k;
    int count =0;
    unordered_map<int,int> temp;
    for(auto i:arr)
    {
       
        if (temp[i]!=0)
        {
            temp[i]++;
        }
        else
        {
            temp[i]=1;
        }
        
        if (temp[i]==t)
        {
           count++; 
        }
        
    }
    
  return count; 
}

int main()
{
    vector<int> vec = {1,1,4,4};
    int n =4;
    int k =2;
    
    int ans =majoritythree(vec,n,k);
    cout<<ans;
    
 

    
    
}