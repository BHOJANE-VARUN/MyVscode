#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
int findzaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    //making the individual width and height toa single vector inorder to sort
    vector<pair<int,int>>env;
    for(int i=0;i<n;i++){
        env.push_back(make_pair(height[i],width[i]));
    }
    //sorting env
    sort(env.begin(),env.end(),compare);
    for(auto i:env)cout<<i.first<<" "<<i.second<<"\n";
    //vector to store the increasing sub-sequence
   vector<int>ans;
   ans.push_back(env[0].second);
   for(int i=1;i<n;i++){
       if(env[i].second>ans.back())
            ans.push_back(env[i].second);
        else{
            //the catchy section- it finds the index in ans where env[i].second's just larger element in ans
            int index=lower_bound(ans.begin(),ans.end(),env[i].second)-ans.begin();
            ans[index]=env[i].second;
        }
   }
   return ans.size();
}
int main()
{
    //6 7 5 10 5
//6 5 6 10 5
    vector<int> h = {6 ,7, 5 ,10, 5};
    vector<int> w = {6, 5 ,6 ,10 ,5};
    cout<<findMaxEnvelopes(h,w,5);
}