#include <iostream>
#include<map>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
node *takeinput()
{
    node *root = NULL;
    string str = "2 4 7 3 8 1 9";
    int i =0;
    while (str[i] != '9')
    {
        if (str[i] != ' ')
        {
            root = insert(root,str[i]-'0');
            
        }
        i++;
    }
    return root;
}
void inordertraversa(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inordertraversa(root->left);
    cout << root->data << " ";
    inordertraversa(root->right);
}
int minterminBST(node *root)
{
    int mini;
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}
int maxterminBST(node *root)
{
    int maxi;
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}
//previous element of the root in inorder traversal
node *predessor(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root = root->left;
    while (root->right)
    {
        root = root->right;
    }
    return root;
}
node *deletion(node *root, int tar)
{
    if (root == NULL)
        return NULL;
    if (root->data == tar)
    {
        if ((root->left==NULL && root->right==NULL))
        {
            return NULL;
        }

        if (root->left == NULL or root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        else
        {
            node *pre = predessor(root);
            root->data = pre->data;
            root->left = deletion(root->left, pre->data);
            return root;
        }
    }
    else if (root->data < tar)
    {
        root->right = deletion(root->right, tar);
    }
    else
    {
        root->left = deletion(root->left, tar);
    }
}
int main()
{
    cout << "enter data to create BST" << endl;
    node *root = takeinput();
    cout << "inorder traversal =" << endl;
    inordertraversa(root);
    cout << endl<< "after deletion" << endl;
    root = deletion(root, 3);
    inordertraversa(root);
}