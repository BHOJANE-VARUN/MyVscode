 #include<iostream>
using namespace std;
    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

pair<bool,int> solve(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return {true,0};
    }
    
    pair<bool,int> lef = solve(root->left);
    if(!lef.first) return {false,-1};
    pair<bool,int> rig = solve(root->right);
    if(!rig.first) return {false,-1};

    if(abs(lef.second-rig.second)<=1)
    {
        pair<bool,int> ans;
        ans.first = true;
        ans.second = max(lef.second,rig.second)+1;
        return ans;
    }
    else{
        return {false,-1};
    }
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return solve(root).first;
}
int main()
{
    return 0;
}