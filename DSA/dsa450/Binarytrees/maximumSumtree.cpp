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

long long solve(BinaryTreeNode<int> * &root,long long &ans)
{
    if(root==NULL)
    {
        return 0;
    }

    long long  lef = solve(root->left,ans);
    long long  rig = solve(root->right, ans);

    ans = max(ans,lef+rig+ root->data);
    long long temp = lef+rig+ root->data;
    return temp;
}
long long maxSubtreeSum(BinaryTreeNode<int> *root){
	// Write your code here.
    long long ans = INT_MIN;
    solve(root, ans);
     return ans;
}
int main()
{
    return 0;
}
