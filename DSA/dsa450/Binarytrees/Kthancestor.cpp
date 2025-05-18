#include <bits/stdc++.h> 
using namespace std;
    template<typename T>
    class BinaryTreeNode
    {
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

// void solve(vector<int> &sk,BinaryTreeNode<int>* root,int tar,int k,int &ans)
// {
   
//     if(root==NULL) return;
//     if(root->data==tar)
//     {   int temp = k-1;
//         if(sk.size()>temp)
//         {
//             if(ans==-1)
//             ans =sk[sk.size()-temp-1];
//         }
//     }
//     sk.push_back(root->data);
//     solve(sk,root->left,tar,k,ans);
//     solve(sk,root->right,tar,k,ans);
//     sk.pop_back();
// }
int solve(BinaryTreeNode<int>*root,int tar,int &k)
{   
    if(root==NULL) return -1;
    if(root->data==tar) return tar;

    int lef = solve(root->left, tar, k);
    int rig = solve(root->right, tar, k);

    if(lef==-1 && rig==-1) return -1;
    else 
    {   k--;
        if(k<=0)
        {
            k= INT_MAX;
            return root->data;
        }
 
        if(lef!=-1)
        return lef;
        else return rig;
    }   
    
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    // Write your code here.
    // vector<int> sk;
    // int ans =-1;
    // solve(sk, root, targetNodeVal,k,ans);
    // return ans;
    int ans =solve(root, targetNodeVal, k);
    return ans==targetNodeVal?-1:ans;
}
int main()
{
    return 0;
}
