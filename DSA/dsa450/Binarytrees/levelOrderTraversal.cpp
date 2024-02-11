#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(node *root)
{
    //  Write your code here.
    if(root==NULL)
        return vector<int>();
    queue<BinaryTreeNode<int>*> qu;
    qu.push(root);
    vector<int> ans;
    ans.push_back(root->val);
    while(!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();
        if(temp->left!=NULL)
        {
            ans.push_back(temp->left->val);
            qu.push(temp->left);
        }
        if (temp->right != NULL) {
            ans.push_back(temp->right->val);

            qu.push(temp->right);
        }
    }
    return ans;
}
int main()
{
    std::cout<<"hello";
}