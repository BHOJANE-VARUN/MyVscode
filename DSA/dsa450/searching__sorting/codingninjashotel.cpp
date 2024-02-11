#include <bits/stdc++.h> 
using namespace std;
bool check(vector<int> &time,int m,long long mid)
{
    
    int count = 0;
    while(m)
    {   if(time[count]>mid)return false;
    int mul = 1;
    long long localtime = 0;
        while(localtime<mid && m)
        {
            if(localtime + time[count]*mul<=mid)
            {
                localtime += time[count]*mul;
                m--,mul++;
            }
            else{
                break;
            }
        }
        count++;
        if(count==time.size() && m)return false; 
    }
    return true;
}
int minCookTime(vector<int> &rank, int m)
{   long long ans = -1;
    sort(rank.begin(),rank.end());
    long long low = 0,high = 1ll*rank[rank.size()-1]*m;
    while(low<=high)
    {
        long long mid = 1ll*((high+low)/2);
        if(check(rank,m,mid))ans = mid,high = mid-1;
        else low = mid +1;
    }
    return ans;
    
}
/*In this approch instead of calculating it is possible or not to cook m dishes in mid time ,we can calculate that each chef
can cook how many dishes in mid time then we sum them and if sum is greater than mid then true else false


    Time Complexity : O(N*log^2(M))
    Space Complexity : O(1)

    Where 'N' is the number of cooks, 
    and 'M' is the number of dishes.


#include <cmath>

int minCookTime(vector<int> &rank, int m)
{
    int low = 1, high = 5 * m * (m + 1);

    // Binary Search
    while (high > low)
    {
        int mid = (high + low) / 2;
        int dishCooked = 0;

        // Calculate total number of dishes prepared in time = 'mid' by 'N' cooks.
        for (int i = 0; i < rank.size(); i++)
        {
            dishCooked += (-1 + sqrt(1 + (8 * mid) / rank[i])) / 2;
        }

        if (dishCooked < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

*/
int main()
{
    /*1 1
10
4 11
1 2 3 4*/
int m = 11;
vector<int> vec = {1,2,3,4};
cout<<minCookTime(vec,m);
}
