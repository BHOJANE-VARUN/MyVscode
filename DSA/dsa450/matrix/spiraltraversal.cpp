#include <bits/stdc++.h>
using namespace std;
vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{   
    vector<int> ans;
 
    int top = 0;
    int down =n-1;
    int left = 0;
    int right =m-1;
    int count = 0;
    while (left<=right && top<=down)
    {   
    for (int i = left; i < right+1; i++)
    {  
    
        ans.push_back(matrix[top][i]);
        count++;
    }
    if(count>=(m*n))
    {
        break;
    };
    for (int j = top+1; j < down; j++)
    {
        ans.push_back(matrix[j][right]);
        count++;
    }
    if(count>=(m*n))
    {
        break;
    };
    for (int k = right;k >= left; k--)
    {
        ans.push_back(matrix[down][k]);
        count++;
    }
    if(count>=(m*n))
    {
        break;
    };
    for (int l = down-1; l > top; l--)
    {
        ans.push_back(matrix[l][left]);
        count++;
    }
    if(count>=(m*n))
    {
        break;
    };
    top++;
    down--;
    left++;
    right--;

    } 
    return ans;
}
int main()
{
    vector<vector<int>> test = {{1,2,3,4},{10,11,12,5},{9,8,7,6}};
    int n =3,m=4;
    vector<int> ans = spiralPathMatrix(test,n,m);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}