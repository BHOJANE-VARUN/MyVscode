#include<iostream>
#include<vector>
using namespace std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
 
int findindex(int root,int s,int e,vector<int>&pre)
{   int i =s;
    while(i<=e and pre[i]<root)
    {
        i++;
    }
    return i;
}
TreeNode* build(int s,int e,vector<int> &pre)
{
    if(s>e)
    {
        return NULL;
    }

    int index = findindex(pre[s], s+1, e, pre);
    TreeNode* root = new TreeNode (pre[s]);
    root->left = build(s+1, index-1, pre);
    root->right = build(index, e, pre);
    return root;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    return build(0, preOrder.size()-1, preOrder);
}
int main()
{
    return 0;
}