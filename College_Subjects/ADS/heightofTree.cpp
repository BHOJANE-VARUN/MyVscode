#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
    int data;
    node* left,*right;
    node()
    {
        data =0;
        left =NULL;
        right = NULL;
    }
}
void helper(int &ans,node* root,int i)
{
    if(root->left==NULL and root->right==NULL)
    {
        ans = max(ans,i);
        return;
    }
    else{
        if(root->left)
            helper(ans,root->left,i+1);
        if(root->right)
            helper(ans,root->right,i+1);
    }
}
int getheight(node* root)
{
    if(root==NULL)
        return -1;
    int ans = 0;
    helper(ans,root,0);
    return ans;
}