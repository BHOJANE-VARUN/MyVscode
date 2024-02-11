#include<iostream>
using namespace std;
    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

TreeNode<int> * find(TreeNode<int> *root)
{
    TreeNode<int> * temp = root->left;
    while(temp->right && temp->right!=root)
    {
        temp = temp->right;
    }
    return temp;
}
void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    TreeNode<int> * cur = root;
    while(cur!=NULL)
    {   if(cur->left==NULL)
        {
            cur = cur->right;
        }
        else
        {
            TreeNode<int>* prede = find(cur);
            if(prede->right==NULL)
            {
                prede->right = cur->right;
                cur->right = cur->left;
                cur ->left = NULL;
                //cur = cur->left;
            }
            //else{
                cur = cur->right;
            //}
        }
    }
}
int main()
{
    return 0;
}