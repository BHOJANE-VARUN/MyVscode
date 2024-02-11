#include<iostream>
#include<vector>
using namespace std;
    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };

// bool bintar(BinaryTreeNode*root,int tar)
// {
//     if(root==NULL) return false;

//     while(root && root->data!=tar)
//     {
//         if(root->data>tar)
//         {
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     if(root) return true;
//     else return false;
// }
// void solve(BinaryTreeNode* root,int s,bool &flag)
// {
//     if(flag==true or root==NULL) return;

//     flag = bintar(root, s-root->data);
//     if(flag) return;
//     solve(root->left, s, flag);
//     solve(root->right,s,flag);
// }
void solve(BinaryTreeNode* root,vector<int>&ans)
{
    if(root==NULL) return;

    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    // bool f = false;
    // solve(root, k, f);
    // return f;
    vector<int> ans;
    solve(root, ans);
    int s=0,e = ans.size()-1;
    while(s<e)
    {   int sum = ans[s]+ans[e];
        if(sum==k)
        {
            return true;
        }
        else if (sum<k)
        {
            s++;
        }
        else{
            e--;
        }
    }
    return false;
}
int main()
{
    return 0;
}