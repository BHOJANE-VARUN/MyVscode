#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

vector<int> getLeftView(TreeNode<int> *root)
{   vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mp;
   queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<TreeNode<int> *,int> temp = q.front();
        q.pop();
        if(mp.find(temp.second)==mp.end())
        mp[temp.second] = temp.first->data;

        if(temp.first->left)
        {
            q.push({temp.first->left,temp.second+1});
        }
        if(temp.first->right)
        {
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(auto i:mp) ans.push_back(i.second);
    return ans;
}
int main()
{
    return 9;
}