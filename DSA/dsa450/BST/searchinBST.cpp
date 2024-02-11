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
bool solve(TreeNode<int> * root,int tar)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==tar) return true;

    return (solve(root->left,tar) || solve(root->right,tar));
}
//binary search operator
bool recsolve(TreeNode<int>*root,int tar)
{
    TreeNode<int>* temp = root;
    while (temp)
    {
        if(temp->data==tar)
        {
            return true;
        }
        else if(temp->data>tar){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
bool findNode(TreeNode <int> * root, int key) {
    // Write your code here.
    return solve(root,key);
}
int main()
{
    return 0;
}