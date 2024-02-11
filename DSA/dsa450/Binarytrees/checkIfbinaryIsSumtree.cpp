#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

pair<bool,int> solve(TreeNode<int>* &root)
{
    if(root==NULL)
    {
        return {true,0};
    }
    pair<bool,int> lef = solve(root->left);
    if(!lef.first && lef.second!=0) return {false,-1};
    pair<bool,int> rig = solve(root->right);
    if(!rig.first && rig.second!=0) return {false,-1};
    int ans = lef.second+rig.second+root->val;
    if(root->val !=lef.second+rig.second && lef.second+rig.second!=0)
    {
        return {false,-1};
    };
    return {true,ans};
}
bool isSumTree(TreeNode<int> *root)
{
    // Write your code here.
    pair<bool,int> ans = solve(root);
    return ans.first;
}
int main()
{
    return 0;
}