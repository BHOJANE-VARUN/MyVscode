#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
    
};
node* buildtree(node* root)
    {   
        cout<<"Enter data :"<<endl;
        int data;
        cin>>data;
        root = new node(data);
        if(data==-1)
        {
            return NULL;
        }
        cout<<"enter data for left node"<<endl;
        root->left = buildtree(root->left);
        cout<<"enter data for right node"<<endl;
        root->right = buildtree(root->right);
        return root;
    }

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// vector<int> getLevelOrder(node *root)
// {
//     //  Write your code here.
//     if(root==NULL)
//         return vector<int>();
//     queue<BinaryTreeNode<int>*> qu;
//     qu.push(root);
//     vector<int> ans;
//     ans.push_back(root->val);
//     while(!qu.empty())
//     {
//         node *temp = qu.front();
//         qu.pop();
//         if(temp->left!=NULL)
//         {
//             ans.push_back(temp->left->val);
//             qu.push(temp->left);
//         }
//         if (temp->right != NULL) {
//             ans.push_back(temp->right->val);

//             qu.push(temp->right);
//         }
//     }
//     return ans;
// }
void levelordertr(node* &root)
{   queue<node*> q;
    q.push(root);
    q.push(NULL);
    //cout<<root->data<<endl;

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    

}
void inordertraversa(node* root)
{   
    if(root==NULL)
    {
        return;
    }
    
   
    
    inordertraversa(root->left);
     cout<<root->data<<" ";
    inordertraversa(root->right);
}
node* buildfromlevel(node* &root)
{   int data;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int lefda,rigda;
        cout<<"enter data for left "<<endl;
        cin>>lefda;
        if(lefda!=-1)
        {
            node* lef = new node(lefda);
            temp->left = lef;
            q.push(temp->left);
        }
        cout<<"enter data for right "<<endl;
        cin>>rigda;
        if(rigda!=-1)
        {
            node* rig = new node(rigda);
            temp->right = rig;
            q.push(temp->right);
        }
    }
   return root; 
}
int main()
{
    node* head=NULL;
    head = buildfromlevel(head);
    //levelordertr(head);
    levelordertr(head);
}