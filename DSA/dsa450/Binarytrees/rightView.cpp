#include<iostream>
#include<queue>
#include<vector>
using namespace std;
    template <typename T>

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

#include "map"
vector<int> printRightView(BinaryTreeNode<int>* root) {
  vector<int> ans;
    if(root==NULL) return ans;
    map<int,int> mp;
   queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<BinaryTreeNode<int> *,int> temp = q.front();
        q.pop();
        // if(mp.find(temp.second)==mp.end())
        mp[temp.second] = temp.first->data;

        if(temp.first->left)
        {
            q.push({temp.first->left,temp.second+1});
        }
        if(temp.first->right)
        {
            q.push({temp.first->right,temp.second+1});
        }
    }
    for(auto i:mp) ans.push_back(i.second);
    return ans;
}
int main()
{
    return 0;
}