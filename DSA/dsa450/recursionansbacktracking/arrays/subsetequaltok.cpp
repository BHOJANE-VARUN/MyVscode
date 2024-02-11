#include <bits/stdc++.h> 
using namespace std;
long long mod = 1e9+7;
void subsets(int k,int index,int n,vector<int> output,vector<int> &arr,int &count,int sum)
{
    if(index>=n)
    {   
        if(sum==k)
        {
            count++;
        }
        return ;
    }

    //exclude

    subsets(k,index+1,n,output,arr,count,sum);
   //include
    int element = arr[index];
    sum = sum%mod;
    sum += element;
    output.push_back(element);
    
    subsets(k,index+1,n,output,arr,count,sum);
}
int main()
{
    vector<int> test = {1000000,2000000,300,4,5,6};
    vector<int> output;
    int count=0;
    subsets(3,0,test.size(),output,test,count,0);
    cout<<count;
}