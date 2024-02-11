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
bool valid(int x,int y,int n)
{
    if( 0<=x && x<=n-1 && 0<=y && y<=n-1)
    {
        return true;
    }
    else{
        return false;
    }
}
void backtrack(vector<vector<int>> &maze,vector<vector<int>> &visit,int n,int x,int y,vector<vector<int>> &ans)
{   visit[x][y]=1;
    if(x==y && x==n-1)
    {   ans.push_back(convert2DTo1D(visit));
        visit[x][y]=0;
        return ;
    }
    

    if((valid(x+1,y,n) && maze[x+1][y]==1) && visit[x+1][y]==0)
    {
        
        backtrack(maze,visit,n,x+1,y,ans);

    }
    if((valid(x,y+1,n) && maze[x][y+1]==1) && visit[x][y+1]==0)
    {
       
        backtrack(maze,visit,n,x,y+1,ans);
    
    }
    if((valid(x,y-1,n) && maze[x][y-1]==1) && visit[x][y-1]==0)
    {
        backtrack(maze,visit,n,x,y-1,ans);
      
    }
    if((valid(x-1,y,n) && maze[x-1][y]==1) && visit[x-1][y]==0)
    {
        
        backtrack(maze,visit,n,x-1,y,ans);
       
    }
    visit[x][y]=0;
}
vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> visit(n,vector<int> (n,0));
    visit[0][0]=1;
    vector<vector<int>> ans;
    backtrack(maze,visit,n,0,0,ans);
    return ans;
}
int main()
{   /*4
1 1 1 0 
1 1 1 0 
1 0 1 1 
0 0 0 1 

*/
    vector<vector<int>> maze = {{1,1,1,0},{1,1,1,0},{1,0,1,1},{0,0,0,1}};
    vector<vector<int>> test = ratInAMaze(maze,4);
    for(auto i:test)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    
}