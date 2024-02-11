#include<bits/stdc++.h>
using namespace std;
void inputarrInt(int *arr,int n)
{   int temp;
    for(int i =0;i<n;i++)
    {
        cin>>temp;
        arr[i] = temp;
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {   
        unordered_map<int,vector<int>> mp;
        int n;
        cin>>n;
        for(int i =0;i<n;i++)
        {
            int temp;
            cin>>temp;
            mp[temp].push_back(i);
        }
        int steps = INT_MAX,clan =-1;
        for(auto i:mp)
        {   
            int cur = i.first;
            int cursteps = i.second[0];
            for(int k =1;k<i.second.size();k++)
            {
                cursteps = max(cursteps,((i.second[k]-i.second[k-1])/2));
            }
            int ele = i.second[i.second.size()-1];
            int now = n - i.second[i.second.size()-1] - 1;
            cursteps = max(cursteps,now);
            if(steps>cursteps)
            {
                steps = cursteps;
                clan = i.first;
            }
            else if(steps==cursteps)
            {
                clan = min(i.first,clan);
            }
        }
         cout<<clan<<" "<<steps<<endl;
    }

}