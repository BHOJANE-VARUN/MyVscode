#include<iostream>
using namespace std;
class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
int predecessor(TreeNode *root , int key)

{

    int predece = -1;

    TreeNode * temp = root;

    while(temp)

    {

        if(temp->data >= key)

        {

            temp = temp->left;

        }

        else if (temp->data <key)

        {

            predece = temp->data;

            temp = temp->right;

        }

    }

    return predece;

}

int successor(TreeNode *root , int key)

{

    int succes = -1;

    TreeNode * temp = root;

    while(temp)

    {

        if(temp->data <= key)

        {

            temp = temp->right;

        }

        else if (temp->data > key)

        {

            succes = temp->data;

            temp = temp->left;

        }

    }

    return succes;

}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)

{

    // Write your code here.

    pair<int,int>ans=make_pair(predecessor(root,key),successor(root,key));

    return ans;

}
int main()
{
    return 0;
}