#include <bits/stdc++.h>
using namespace std;
int distance(vector<int> vec,int n)
{
    int mini = *min_element(vec.begin(),vec.end());                
    int maxi = *max_element(vec.begin(),vec.end());
    return maxi-mini;
}
int main()
{
    vector<int> vc = {1,2,2,4};
    int n =4;
    cout<<distance(vc,n);
}