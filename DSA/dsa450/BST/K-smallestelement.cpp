#include<iostream>
using namespace std;
    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };


int solve(TreeNode<int> *root,int &k)
{   if(root==NULL) return -1;
    

   int ele =  solve(root->left, k);
   if(ele!=-1) return ele;
    k--;
   if(k==0) return root->data;
   int ele2 =  solve(root->right, k);
   if(ele2!=-1) return ele2;
   return -1;
}
int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.
    int temp = k;
    return solve(root,temp);
}
int main()
{
    return 0;
}