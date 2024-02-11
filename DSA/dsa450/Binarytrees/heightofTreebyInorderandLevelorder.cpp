#include <bits/stdc++.h> 
using namespace std;
#include <bits/stdc++.h> 
class node
{
    public:
    int hi,li,ri;
    node(int x,int y,int z)
    {
        hi = x;
        li = y;
        ri = z;
    }
};
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    map<int,int> mp;
    for(int i =0;i<N;i++) mp[inorder[i]] = i;
    queue<node> q;
    int ans =INT_MIN;
    q.push(node(0,0,N-1));
    for(int i =0;i<N;i++)
    {
        node temp = q.front();
        q.pop();
        int hi = temp.hi;
        int li = temp.li;
        int ri = temp.ri;
        ans = max(ans,hi);
        int index = mp[levelOrder[i]];
        if(index-1>=li)
        {
            q.push(node(hi+1,li,index-1));
        }
        if(index+1<=ri)
        {
            q.push(node(hi+1,index+1,ri));
        }
    }
    return ans;
}