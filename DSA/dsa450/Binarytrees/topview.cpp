#include<iostream>
#include<vector>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

// void solverig(TreeNode<int> *&root,int cur,int view,vector<int> &ans)
// {
//     if(root==NULL) return;

//     if(cur>view)
//     {
//         ans.push_back(root->data);
//         view =cur;
//     }
//     solverig(root->right,cur+1,view,ans);
//     solverig(root->left,cur-1,view,ans);
// }
// void solveleft(TreeNode<int> *&root,int cur,int view,vector<int> &ans)
// {   
//     if(root==NULL) return;

//     if(cur<view)
//     {
//         ans.push_back(root->data);
//         view = cur;
//     }
//     solveleft(root->left,cur-1,view,ans);
//     solveleft(root->right,cur+1,view,ans);
// }
// vector<int> getTopView(TreeNode<int> *root)
// {
//     vector<int> ans;
//     solveleft(root->left,-1,0,ans);
//     ans.push_back(root->data);
//     solverig(root->right,1,0,ans);
//     return ans;
// }
#include "map"
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// void solverig(TreeNode<int> *&root,int cur,int &view,vector<int> &ans)
// {
//     if(root==NULL) return;

//     if(cur>view)
//     {
//         ans.push_back(root->data);
//         view =cur;
//     }
//     solverig(root->right,cur+1,view,ans);
//     solverig(root->left,cur-1,view,ans);
// }
// void solveleft(TreeNode<int> *&root,int cur,int &view,vector<int> &ans)
// {   
//     if(root==NULL) return;
//     if(cur<view)
//     {
//         ans.push_back(root->data);
//         view = cur;
//     }
//     solveleft(root->left,cur-1,view,ans);
//     solveleft(root->right,cur+1,view,ans);
    
// }
// vector<int> getTopView(TreeNode<int> *root)
// {
//     vector<int> ans;
//     int view =0;
//     solveleft(root->left,-1,view,ans);
//     reverse(ans.begin(),ans.end());
//     ans.push_back(root->data);
//     view = 0;
//     solverig(root->right,1,view,ans);
//     return ans;
// }
vector<int> getTopView(TreeNode<int> *root)
{
    queue<pair<TreeNode<int> *,int>> q;
    vector<int> ans;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty())
    {
        pair<TreeNode<int> *,int> temp = q.front();
        q.pop();
        if(mp.find(temp.second)==mp.end())
        mp[temp.second] = temp.first->data;

        if(temp.first->left)
        {
            q.push({temp.first->left,temp.second-1});
        }
        if(temp.first->right)
        {
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(auto i:mp) ans.push_back(i.second);
    return ans;
}
// int l,r;
// vector<int> ans;
// void helper(TreeNode<int> *root, int c)
// {
//     if(root)
//     {
//         if(c>l)
//         {
//             ans.push_back(root->data);
//             l++;
//         }
//         helper(root->left,c+1);
//         helper(root->right,c-1);
//     }
// }
// void helper2(TreeNode<int> *root, int c)
// {
//     if(root)
//     {
//         if(c<r)
//         {
//             ans.push_back(root->data);
//             r--;
//         }
//         helper2(root->right,c-1);
//         helper2(root->left,c+1);
//     }    
// }
// vector<int> getTopView(TreeNode<int> *root) {
//     // Write your code here.
//     l=0;
//     r=1;
//     ans.clear();
//     if (root) {
//         helper(root, 1);
//         reverse(ans.begin(),ans.end());
//         helper2(root,1);
//     }
//     return ans;
// }


int main()
{
    return 0;
}
