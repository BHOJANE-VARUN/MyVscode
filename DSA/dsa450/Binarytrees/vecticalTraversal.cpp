#include <bits/stdc++.h> 
using namespace std; 
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};



vector<int> verticalOrderTraversal(TreeNode<int> *root)
{   vector<int> ans;
    if(root==NULL) return ans;
    //    Write your code here.
    map<int,map<int,vector<int>>> mp;
    queue<pair<TreeNode<int>*,pair<int,int>>> que;
    que.push({root,{0,0}});
    while(!que.empty())
    {
        pair<TreeNode<int>*,pair<int,int>> temp = que.front();
        que.pop();
        mp[temp.second.first][temp.second.second].push_back(temp.first->data);
        if(temp.first->left)
        {
            que.push({temp.first->left,{temp.second.first-1,temp.second.second+1}});
        }
        if(temp.first->right)
        {
            que.push({temp.first->right,{temp.second.first+1,temp.second.second+1}});
        }
    }
    for(auto i:mp)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
            
        }
    }
    return ans;
}
int main()
{
    return 0;
}