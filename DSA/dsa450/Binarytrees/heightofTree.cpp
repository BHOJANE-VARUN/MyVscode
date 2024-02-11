#include<iostream>
using namespace std;
    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
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
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    return solve(root);
}
int main()
{
    return 0;
}