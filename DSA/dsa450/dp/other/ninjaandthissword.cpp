#include <bits/stdc++.h> 
using namespace std;
int solve(vector<vector<int>>& mat,vector<vector<int>> & mat2,int i ,int j,int k,int v,int &maxi)
{
    if(i>=mat.size() || j>=mat[0].size() || k>=mat2.size() || v>=mat2.size()) return 0;

    int ri = solve(mat,mat2,i,j+1,k,v+1,maxi);
    int diag = solve(mat,mat2,i+1,j+1,k+1,v+1,maxi);
    int dowm = solve(mat,mat2,i+1,j,k+1,v,maxi);

    if(mat[i][j]==mat2[k][v])
    {
        int ans = 1 + min(ri,min(diag,dowm));
        maxi = max(ans,maxi);
        return ans;
    }
    else{
        return 0;
    }
}
int ninjaAndSword(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int n1, int m1, int n2, int m2) 
{
	// Write your code here.
    int ans =0;
    int s = solve(mat1,mat2,0,0,0,0,ans);
    return ans*ans;
}
int main()
{
    vector<vector<int>> mat1 = {{1,2},{1,2}};
    int n1 = mat1.size(),m1 = mat1[0].size();
    vector<vector<int>> mat2 = {{1,2},{1,2}};
    cout<<ninjaAndSword(mat1,mat2,2,2,2,2);
}