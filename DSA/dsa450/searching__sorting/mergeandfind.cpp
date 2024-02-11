#include <bits/stdc++.h> 
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
vector<int> kthSmallest(vector<vector<int>> &ranges, vector<int> &queries) {
	sort(ranges.begin(),ranges.end());
    mergeIntervals(ranges);
    vector<int> vec;
    for(auto i:ranges)
    {
        for(int j =i[0];j<=i[1];j++)
        {
            vec.push_back(j);
        }
    }
    vector<int> ans;
    for(auto i:queries)
    {
        if(i>vec.size())ans.push_back(-1);
        else{
            ans.push_back(vec[i-1]);
        }
    }
    return ans;
}
int main()
{   /*5 6
1 2
1 1
1 2
1 2 3 5*/
    vector<vector<int>> vec = {{5,6}, {1,2}, {1,1}, {1,2}};
    vector<int> ques = {1,2,3,5};
    vector<int> test = kthSmallest(vec,ques);
    for(auto i:test)cout<<i<<"  ";   
}