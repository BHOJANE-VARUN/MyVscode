#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

BinaryTreeNode<int> * solve(BinaryTreeNode<int>* &root, BinaryTreeNode<int>* &u, BinaryTreeNode<int>* &v)
{
    if(root==u)
    return u;
    if(root==v)
        return v;
    if(root==NULL) return NULL;

    BinaryTreeNode<int> * lef = solve(root->left,u,v);
    BinaryTreeNode<int> * rig = solve(root->right,u,v);

    if(lef!=NULL and rig!=NULL) return root;
    else if(lef==NULL and rig==NULL) return NULL;
    else if(lef==NULL) return rig;
    else return lef;
}
BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root, BinaryTreeNode<int>* u, BinaryTreeNode<int>* v) {
    // Write your code here.
    return solve(root,u,v);
}
int main()
{
    return 0;
}