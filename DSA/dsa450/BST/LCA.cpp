#include<iostream>
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



TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(P==NULL or Q==NULL) return NULL;
    if(root==NULL) return NULL;
    TreeNode *temp = root;
    while(temp!=NULL)
    {
        if(temp->data>P->data && temp->data>Q->data)
        {
            temp = temp->left;
        }
        else if(temp->data<P->data && temp->data<Q->data)
        {
            temp = temp->right;
        }
        else{
            return temp;
        }
    }
    return NULL;
}
int main()
{
    return 0;
}