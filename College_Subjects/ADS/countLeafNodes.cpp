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
void helperleaf(int &ans,node* root)
{
    if(root->left==NULL and root->right==NULL)
    {
        ans = ans+1;
        return;
    }
    else{
        if(root->left)
            helperleaf(ans,root->left);
        if(root->right)
            helperleaf(ans,root->right);
    }
}
int getleafcount(node* root)
{
    if(root==NULL)
        return -1;
    int ans = 0;
    helperleaf(ans,root);
    return ans;
}