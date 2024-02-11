#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void solve(TreeNode<int>* root,vector<int>&ans)
{
    if(root==NULL) return;

    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    solve(root,ans);
    TreeNode<int> * var = new TreeNode<int> (ans[0]);
    TreeNode<int> * cur = var;
    for(int i =1;i<ans.size();i++)
    {
        cur->right = new TreeNode<int> (ans[i]);
        cur = cur ->right;
    }
    return var;
}
int main()
{
    return 0;
}