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


vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(root==NULL) return vector<int>();
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> save(size);
        for(int i =0;i<size;i++)
        {
            BinaryTreeNode<int> * temp = q.front();
            q.pop();
            int index = flag? i:size-i-1;
            save[index] = temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
        for(auto i:save)
        ans.push_back(i);  
        flag = !flag;
    }
    return ans;
}
int main()
{
    return 0;
}
