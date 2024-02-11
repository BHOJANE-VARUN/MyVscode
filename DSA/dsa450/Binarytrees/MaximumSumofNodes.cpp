#include <bits/stdc++.h> 
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

//************************************************************/

pair<int,int> solve(TreeNode<int> *root)
{
    if(root==NULL) return {0,0};

    pair<int,int> lef = solve(root->left);
    pair<int,int> rig = solve(root->right);

    int excl = lef.second + rig.second + root->data;
    int incl = max(lef.first,lef.second) + max(rig.first,rig.second);
    return {excl,incl};
}
int maximumSumOfNodes(TreeNode<int> *root)
{
	//    Write your code here
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
    
}
int main()
{
    return 0;
}