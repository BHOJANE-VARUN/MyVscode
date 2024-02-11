#include<iostream>
#include<vector>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void solve(TreeNode<int>* root,vector<int>&ans)
{
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    else{
        solve(root->left,ans);
        solve(root->right,ans);
    }
}
void traverseleft(TreeNode<int> *root,vector<int>&ans)
{
    if(root==NULL or (root->left==NULL and root->right==NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left)
    traverseleft(root->left, ans);
    else traverseleft(root->right, ans);
}
void traverserig(TreeNode<int> * root,vector<int>&ans)
{
    if(root==NULL or (root->left==NULL and root->right==NULL))
    {
        return;
    }
    
    if(root->right)
    traverserig(root->right, ans);
    else traverserig(root->left, ans);
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL) return vector<int>();
    vector<int> ans;
    ans.push_back(root->data);
    traverseleft(root->left, ans);
    solve(root,ans);
    // solve(root->right,ans);
    traverserig(root->right, ans);
    return ans;
}
int main(){
    return 0;
}
