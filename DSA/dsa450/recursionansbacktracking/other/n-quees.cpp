#include <bits/stdc++.h> 
using namespace std; 
std::vector<int> convert2DTo1D(const std::vector<std::vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();

    std::vector<int> result(height * width);

    int index = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            result[index++] = matrix[y][x];
        }
    }

    return result;
}
bool valid(vector<pair<int,int>> &output,int x,int y)
{
    for(auto i:output)
    {
        if(i.first==x || i.second==y || i.first-i.second==x-y || i.first+i.second==x+y)
        {
            return false;
        }
    }
    return true;
}
void solve(int y,int n,vector<pair<int,int>> &output,vector<vector<pair<int,int>>> &ans)
{
    //base case
    if(y==n)
    {
        ans.push_back((output));
        return ;
    }


    for (int i = 0; i < n; i++)
    {
        if(valid(output,i,y))
        {   
            output.push_back({i,y});
            solve(y+1,n,output,ans);
            output.pop_back();
        }
    }
    
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<pair<int,int>>> ans;
    vector<pair<int,int>> output;
    solve(0,n,output,ans);
    vector<vector<int>> ren(ans.size(),vector<int> ((n*n),0));
   int k =0;
   for(auto i:ans)
   {
        for(auto j:i)
        {
            ren[k][(j.first*n)+j.second]=1;
        }
        k++;
   }
    return ren; 
}
int main()
{   int n = 4;
   vector<vector<int>> ren= nQueens(n);
   for(auto i:ren)
   {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
       cout<<"\n";
   }
}