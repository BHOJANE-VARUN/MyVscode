#include <bits/stdc++.h> 
using namespace std;
class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void solve(TreeNode* &root,vector<int> &ans)
{
    if(root==NULL) return;
    ans.push_back(root->val);
    solve(root->left,ans);
    solve(root->right,ans);
}
vector<int> preorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int> ans;
    solve(root,ans); 
    return ans;
}

int main()
{
    return 0;
}