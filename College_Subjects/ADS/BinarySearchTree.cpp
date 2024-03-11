#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left,*right;
    node(int data)
    {
        this->data = data;
        left = NULL,right = NULL;
    }
    node()
    {
        data = 0;
        left = NULL,right = NULL;
    }
};
node* insert(node* head,int data)
{
    node* save = head;
    node* cur = new node(data);
    if(head)
    {
        while(head)
        {
            if(head->data>data)
            {
                if(head->left)
                {
                    head = head->left;
                }
                else{
                    head->left = cur;
                    break;
                }
            }
            else{
                if(head->right)
                {
                    head = head->right; 
                }
                else{
                    head->right = cur;
                    break;
                }
            }
        }
    }
    else save = cur;
    return save;
}
void inorder(node*head)
{
    if(head==NULL) return;

    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
void preorder(node*head)
{
    if(head==NULL) return;

    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
void postorder(node*head)
{
    if(head==NULL) return;

    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}
node* predessor(node*head)
{
    if(head==NULL) return NULL;
    head = head->left;
    if(head)
    {
        while(head->right)
        {
            head = head->right;
        }
        return head;
    }
    return NULL;
}
node* sucessor(node*head)
{
    if(head==NULL) return NULL;
    head = head->right;
    if(head)
    {
        while(head->left)
        {
            head = head->left;
        }
        return head;
    }
    return NULL;
}
node* delet(node*head,int tar)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==tar)
    {
        if(head->left==NULL and head->right==NULL)
        {
            return NULL;
        }
        else if(head->left==NULL or head->right==NULL)
        {
            return head->left==NULL? head->right:head->left;
        }
        else{
            node* pre = predessor(head);
            head->data = pre->data;
            head ->left = delet(head->left,head->data);
            return head;
        }
    }
    else if(head->data>tar)
    {
        head->left = delet(head->left,tar);
        return head;
    }
    else{
        head->right = delet(head->right,tar);
        return head;
    }
}
int main()
{
    node* head = NULL;
    head = insert(head,3);
    head = insert(head,2);
    head = insert(head,1);
    head = insert(head,4);
    head = insert(head,5);
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    postorder(head);
    cout<<endl;
    head = delet(head,1);
    inorder(head);
    cout<<endl;
}
