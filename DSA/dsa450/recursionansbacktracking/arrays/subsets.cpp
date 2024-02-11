#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
void subsets(int index,int n,vector<int> output,vector<int> arr,vector<vector<int>> &ans)
{
    if(index>=n)
    {   ans.push_back(output);
        return ;
    }

    //exclude

    subsets(index+1,n,output,arr,ans);
   //include
    int element = arr[index];
    output.push_back(element);
    
    subsets(index+1,n,output,arr,ans);
}
int main()
{
    vector<int> test = {1,2,3};
    vector<int> output;
    vector<vector<int>> ans;
    subsets(0,test.size(),output,test,ans);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
