#include<bits/stdc++.h>
#define int long long int
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl
#define MOD 1000000007
//const int maxsize = 1e5;
//int arr[maxsize+1];
#define test int monu;cin>>monu;while(monu--)
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>> s;
        vector<vector<int>> visit(heights.size(),vector<int> (heights[0].size(),INT_MAX));
        int n = heights.size(),m = heights[0].size();
        s.insert({0,{0,0}});
        visit[0][0] = 0;
        int dir[] = {0,1,0,-1,0};
        while (s.size())
        {
            int cost = (*s.begin()).first,a = (*s.begin()).second.first, b = (*s.begin()).second.second;
            s.erase(s.begin());
            if(a==n-1 and b==m-1)
                return cost;
            for(int i =0;i<4;i++)
            {
                int row = dir[i] + a;
                int col = dir[i+1] + b;
                if(row>=0 and col>=0 and row<n and col<m)
                {
                    int move = max(abs(heights[a][b]-heights[row][col]),cost);
                   // cout<<cost<<" "<<row<<" "<<col<<endl;
                    if(move<visit[row][col])
                    {
                        visit[row][col] = move;
                        s.insert({move,{row,col}});
                    }
                }
            }
        }
        return visit[n-1][m-1];
    }
};
signed main()
{
test
{
    
}
//dusro ka code copy karne se ghar nahi chalta bhai
}