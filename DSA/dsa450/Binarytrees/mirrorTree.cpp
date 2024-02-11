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

void mirrorTree(BinaryTreeNode<int> *root) {
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> * temp = q.front();
        q.pop();
        swap(temp->left, temp->right);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main()
{
    return 0;
}