
#include<iostream>
using namespace std;

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


bool solve(BinaryTreeNode<int> * r1,BinaryTreeNode<int>* r2)
{
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL or r2==NULL) return false;

    if(r1->data==r2->data)
    {
        bool lef = solve(r1->left, r2->left);
        bool rig = solve(r1->right, r2->right);
        return lef and rig;
    }
    else{
        return false;
    }
}
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
    	 return solve(root1, root2);
}
int main()
{
    return 0;
}