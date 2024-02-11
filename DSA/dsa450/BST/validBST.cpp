#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };


// vector<int> ans;
// void solve(BinaryTreeNode<int>*root)
// {
//     if(root==NULL) return;
//     solve(root->left);
//     ans.push_back(root->data);
//     solve(root->right);
    
// }
bool solve(BinaryTreeNode<int>* root,int min, int max){

    if(root==NULL){

        return true;

    }

    if(root->data>=min && root->data<=max){

        bool left=solve(root->left,min,root->data-1);

        bool right=solve(root->right,root->data+1,max);

        return left&&right;

 

    }

    else

        return false;

    

}

bool validateBST(BinaryTreeNode<int>* root) 

{

    return solve(root,INT_MIN,INT_MAX);

}
int main()
{
    return 0;
}