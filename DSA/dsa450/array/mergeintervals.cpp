#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size(), i = 1, rs = 0;
    while (i < n)
    {
        if (intervals[rs][0] >= intervals[i][0] && intervals[rs][1] <= intervals[i][1])
        {
            int j = i++;
            while (rs != -1 && intervals[rs][1] >= intervals[j][0])
            {   
                intervals[rs][0] = intervals[j][0];
                intervals[rs][1] = intervals[j][1];
                j--;
                rs--;
            }
            rs++;
        }
        else if (intervals[rs][1] >= intervals[i][0])
        {
            intervals[rs][0] = min(intervals[rs][0], intervals[i][0]);
            intervals[rs][1] = max(intervals[rs][1], intervals[i][1]);
            i++;
        }
        else
        {
            intervals[++rs][0] = intervals[i][0];
            intervals[rs][1] = intervals[i++][1];
        }
    }

    intervals.resize(rs+1);
    return intervals;
}
int main()
{
    vector<vector<int>> vec = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
     vec =mergeIntervals(vec);
    for (int i = 0; i <vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout<<vec[i][j]<<endl;
        }
    vector
        
    }    
}