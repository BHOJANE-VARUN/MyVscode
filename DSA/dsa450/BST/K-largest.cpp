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



void solve(TreeNode<int>*root,int &k,int &ans)
{
    if(root==NULL or ans!=-1) return;

    solve(root->right,k,ans);
    k--;
    if(k==0) ans =root->data;
    solve(root->left,k,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans =-1;
    int temp =k;
    solve(root,k,ans);
    return ans;
}
int main()
{
    return 9;
}
