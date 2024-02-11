#include<iostream>
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

int solve(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lef = solve(root->left)+1;
    int rig = solve(root->right) +1;
    return max(lef,rig);
}
pair<int,int> fastsolve(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    pair<int,int> opt = fastsolve(root->left);
    pair<int,int> opt2 = fastsolve(root->right);
    int opt3 = opt.first + opt2.first;
    pair<int,int> ans;

    ans.second = max(opt3,max(opt.second,opt2.second));
    ans.first = max(opt.first,opt2.first)+1;

    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    // if(root==NULL)
    // {
    //     return 0;
    // }
    // int opt = diameterOfBinaryTree(root->left);
    // int opt2 = diameterOfBinaryTree(root->right);
    // int opt3 = solve(root->left)  + solve(root->right);
    // return max(opt,max(opt2,opt3));
    return fastsolve(root).second;
}
int main()
{
    return 0;
}
