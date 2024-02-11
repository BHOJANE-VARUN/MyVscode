#include<iostream>
#include<vector>
#include<queue>
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

#include "map"
vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.'
        vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<TreeNode<int> *,int> temp = q.front();
        q.pop();
        
        mp[temp.second] = temp.first->data;

        if(temp.first->left)
        {
            q.push({temp.first->left,temp.second-1});
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
    return 0;
}
