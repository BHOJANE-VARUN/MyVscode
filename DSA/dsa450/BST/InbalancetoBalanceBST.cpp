#include<iostream>
#include<vector>
using namespace std;
    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
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
TreeNode<int> * build(int s,int e,vector<int>&ans)
{
    if(s>e) return NULL;
    if(s==e)
    {
        return new TreeNode<int> (ans[s]);
    }
    int mid = (s+e)/2;
    TreeNode<int> * root = new TreeNode<int> (ans[mid]);
    root->left = build( s, mid-1, ans);
    root->right = build(mid+1, e, ans);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> ans;
    solve(root, ans);
    return build(0, ans.size()-1, ans);
}
int main()
{
    return 0;
}
