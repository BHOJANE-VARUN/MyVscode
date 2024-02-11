#include<iostream>
#include<vector>
#include<map>
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


TreeNode<int> * solve(vector<int> &ino,vector<int> &preo,int s,int e,int &ind,map<int,int> &mp)
{
    if(ind>=preo.size() or s>e)
    {
        return NULL;
    }
    int ele = preo[ind++];
    TreeNode<int> * root = new TreeNode<int>(ele);
    int pos = mp[ele];
    TreeNode<int> *lef = solve(ino, preo, s, pos-1, ind,mp);
    TreeNode<int> *rig = solve(ino, preo, pos+1, e, ind,mp);
    root->left = lef;
    root->right = rig;
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int index =0;
    map<int,int> mp;
    for(int i =0;i<inorder.size();i++) mp[inorder[i]] = i;
    return solve(inorder, preorder,0,preorder.size()-1,index,mp);
}
int main()
{
    return 0;
}