#include <bits/stdc++.h> 
using namespace std;
bool subsetofother(int n, int k, vector<int> &arr1,vector<int> &arr2)
{   
    if (k>n)
    {
        return false;
    }
    
    for (int i = 0; i < k; i++)
    { int temp =0;
        for (int j = 0; j <n; j++)
        {
            if (arr2[i]==arr1[j])
            {
                arr1[j]=INT_MIN;
                temp =1;
                break;
            }
            
            
            
        }
        if(temp==0){
        return false;
        }
    }
    return true;
    
    

    
}
int main()
{
    vector<int> vec1 = {1,2,3,4};
    vector<int> vec2 = {1,4,2,3,3};
    int n = 4;
    int k = 5;
    cout<<subsetofother(n,k,vec1,vec2);
}