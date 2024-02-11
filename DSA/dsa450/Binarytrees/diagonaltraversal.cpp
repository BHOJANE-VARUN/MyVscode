#include <bits/stdc++.h> 
using namespace std;
    template<typename T>
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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
//*************************************************************/
// void solve(BinaryTreeNode<int>*root,map<int,vector<int>> &mp,int level)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     mp[level].push_back(root->data);

//     solve(root->left,mp,level+1);
//     solve(root->right,mp,level);

// }
vector<int> diagonalPath(BinaryTreeNode<int>* root) {
    // Write your code here.
    // vector<int> ans;
    // if(root==NULL) return ans;
    // map<int,vector<int>> mp;
    // int level =0;
    // solve(root, mp, level);
    // for(auto &i: mp)
    // {
    //     for(auto &j:i.second)
    //     {
    //         ans.push_back(j);
    //     }
    // }
    // return ans;
    queue<BinaryTreeNode<int>*> que;
    que.push(root);
    vector<int> ans;
    BinaryTreeNode<int> * temp = root;
    while(!que.empty())
    {
        ans.push_back(temp->data);
        if(temp->left)
        {
            que.push(temp->left);
        }
        if(temp->right)
        {
            temp = temp->right;
        }
        else{
            
            que.pop();
            if(!que.empty())
            temp  = que.front();
        }
    }
    return ans;
}
int main()
{
    return 0;
}