// #include<iostream>
// #include<stack>
// using namespace std;
// class node
// {
//     public:
//     int data;
//     node* left,*right;
//     node(int data)
//     {
//         this->data = data;
//         left = NULL,right = NULL;
//     }
//     node()
//     {
//         data = 0;
//         left = NULL,right = NULL;
//     }
// };
// node* insert(node* head,int data)
// {
//     node* save = head;
//     node* cur = new node(data);
//     if(head)
//     {
//         while(head)
//         {
//             if(head->data>data)
//             {
//                 if(head->left)
//                 {
//                     head = head->left;
//                 }
//                 else{
//                     head->left = cur;
//                     break;
//                 }
//             }
//             else{
//                 if(head->right)
//                 {
//                     head = head->right; 
//                 }
//                 else{
//                     head->right = cur;
//                     break;
//                 }
//             }
//         }
//     }
//     else save = cur;
//     return save;
// }
// void inorder(node*head)
// {
//     if(head==NULL) return;

//     inorder(head->left);
//     cout<<head->data<<" ";
//     inorder(head->right);
// }
// void inorderiteratively(node* root)
// {
//     stack<node*> s;
//     node* curr = root;
 
//     while (curr != NULL || s.empty() == false) {
         
//         // Reach the left most node of the
//         // curr node
//         while (curr != NULL) {
             
//             // Place pointer to a tree node on
//             // the stack before traversing
//             // the node's left subtree
//             s.push(curr);
//             curr = curr->left;
//         }
 
//         // Current must be NULL at this point
//         curr = s.top();
//         s.pop();
 
//         cout << curr->data << " ";
 
//         // we have visited the node and its
//         // left subtree.  Now, it's right
//         // subtree's turn
//         curr = curr->right;
 
//     }
// }
// void preorder(node*head)
// {
//     if(head==NULL) return;

//     cout<<head->data<<" ";
//     preorder(head->left);
//     preorder(head->right);
// }
// void preorderiteratively(node* head)
// {
//     node * cur = head;
//     stack<node*> s;
//     while(!s.empty() or cur!=NULL)
//     {
//         while(cur)
//         {
//             cout<<cur->data<<" ";
//             s.push(cur);
//             cur = cur->left;
//         }
//         node * temp = s.top();
//         s.pop();
//         cur = temp->right;
//     }
//     cout<<endl;
// }
// void postorder(node*head)
// {
//     if(head==NULL) return;

//     postorder(head->left);
//     postorder(head->right);
//     cout<<head->data<<" ";
// }
// node* predessor(node*head)
// {
//     if(head==NULL) return NULL;
//     head = head->left;
//     if(head)
//     {
//         while(head->right)
//         {
//             head = head->right;
//         }
//         return head;
//     }
//     return NULL;
// }
// node* sucessor(node*head)
// {
//     if(head==NULL) return NULL;
//     head = head->right;
//     if(head)
//     {
//         while(head->left)
//         {
//             head = head->left;
//         }
//         return head;
//     }
//     return NULL;
// }
// node* delet(node*head,int tar)
// {
//     if(head==NULL)
//     {
//         return NULL;
//     }
//     if(head->data==tar)
//     {
//         if(head->left==NULL and head->right==NULL)
//         {
//             return NULL;
//         }
//         else if(head->left==NULL or head->right==NULL)
//         {
//             return head->left==NULL? head->right:head->left;
//         }
//         else{
//             node* pre = predessor(head);
//             head->data = pre->data;
//             head ->left = delet(head->left,head->data);
//             return head;
//         }
//     }
//     else if(head->data>tar)
//     {
//         head->left = delet(head->left,tar);
//         return head;
//     }
//     else{
//         head->right = delet(head->right,tar);
//         return head;
//     }
// }
// int main()
// {
//     node* head = NULL;
//     head = insert(head,3);
//     head = insert(head,2);
//     head = insert(head,1);
//     head = insert(head,4);
//     head = insert(head,5);
//     preorderiteratively(head);
//     // cout<<endl;
//     // preorder(head);
//     // cout<<endl;
//     // postorder(head);
//     // cout<<endl;
//     // head = delet(head,1);
//     // inorderiteratively(head);
//     cout<<endl;
// }
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left,*right;
    node(int d)
    {
        data =d;
        left = NULL;
        right = left;
    }
};
node* insert(node* root,int data)
{
    
    if(root==NULL)
    {
        node* cur = new node(data);
        return cur;
    }
    else{
        if(data<=root->data)
        {
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
    }
    return root;
}
node* preseccor(node* root)
{
    if(root==NULL)
        return NULL;
    root = root->left;
    while(root->right)
        root = root->right;
    return root;
    
}
node* delet(node* root,int data)
{
    if(root==NULL)
        return NULL;
    if(root->data==data)
    {
        if(root->left==NULL and root->right==NULL)
            return NULL;
        else if(root->left and root->right)
        {
            node* pre = preseccor(root);
            root->data = pre->data;
            root->left = delet(root->left,root->data);
            return root;
        }
        else{
            node* cur;
            if(root->left)
                cur = root->left;
            if(root->right)
                cur = root->right;
            delete root;
            return cur;
        }
    }
    else if(root->data>data)
    {
        root->left = delet(root->left,data);
        return root;
    }
    else{
        root->right = delet(root->right,data);
        return root;
    }
}
#include<stack>
void preorderiteratively(node* root)
{
    stack<node*> sk;
    sk.push(root);
    while(!sk.empty())
    {
        if(cur->right)
            sk.push(root->right);
        node* cur = sk.top();
        sk.pop();
        cout<<cur->data<<" ";
        if(root->left)
            sk.push(root->left);
    }
    cout<<endl;
}
void inorder(node* root)
{
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node* head = NULL;
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    head = insert(head,2);
    head = insert(head,1);
    inorder(head);cout<<endl;
    delet(head,1);
    inorder(head);
    preorderiteratively(head);
    cout<<endl;
}

