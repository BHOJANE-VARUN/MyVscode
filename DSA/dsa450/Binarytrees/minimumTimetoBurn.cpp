#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void mapped(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &mp, BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left)
    {
        mp[root->left] = root;
    }
    if (root->right)
    {
        mp[root->right] = root;
    }
    mapped(mp, root->left);
    mapped(mp, root->right);
}
BinaryTreeNode<int> *getnode(BinaryTreeNode<int> *root, int tar)
{
    if (root == NULL)
        return NULL;
    if (root->data == tar)
        return root;

    BinaryTreeNode<int> *lef = getnode(root->left, tar);
    if (lef)
        return lef;
    BinaryTreeNode<int> *rig = getnode(root->right, tar);
    if (rig)
        return rig;
}
int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> mp;
    mp[root] = NULL;
    mapped(mp, root);
    BinaryTreeNode<int> *str = getnode(root, start);
    queue<BinaryTreeNode<int> *> q;
    q.push(str);
    map<BinaryTreeNode<int> *, bool> visit;
    visit[str] = true;
    bool f = 0;
    int count = 0;
    while (!q.empty())
    {   f = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            if (temp->left && visit.find(temp->left) == visit.end())
            {
                f = 1;
                visit[temp->left] = true;
                q.push(temp->left);
            }
            if (temp->right && visit.find(temp->right) == visit.end())
            {
                f = 1;
                visit[temp->right] = true;
                q.push(temp->right);
            }
            if (mp[temp] && visit.find(mp[temp]) == visit.end())
            {
                f = 1;
                visit[mp[temp]] = true;
                q.push(mp[temp]);
            }
        }
        if (f)
            count++;
    }

    return count;
}
int main()
{
    return 0;
}
