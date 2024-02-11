#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> ans;
    vector<int> one ={};
    ans.push_back(one);
    int a =0;
    for (int i = 0; i < arr.size(); i++)
    {
        int t = ans.size();
        for (int j = 0; j < t; j++)
        {
            vector<int> temp = ans.at(j);
            temp.push_back(arr[i]);
            a = accumulate(temp.begin(), temp.end(), 0);
            ans.push_back(temp);
        if(a==k)
        {
            //return true;
        }
        }
        
    } 
   // return false;
    return ans;
}
int main()
{
    vector<int> vec = {4,3,2,1};
    int n = 4;
    int k = 5;
    vector<vector<int>> asn = subsetSumToK(n,k,vec);
    for(int i =0;i<asn.size();i++)
    {
        for (int j = 0; j < asn[i].size(); j++)
        {
            cout<<asn[i][j]<<" ";
        }
        cout<<endl;
    }
}