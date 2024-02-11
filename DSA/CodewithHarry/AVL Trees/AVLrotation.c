/*struct of avl tree contain one more element which is height of node*/
/*binary tree is a tree in which one node is connected to only 1 or 2 or null nodes*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *ptrlf;
  struct node *ptrri;
  int data;
  int height;
};
struct node* maker(int dat)
{
    struct node*ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = dat;
    ptr->ptrlf = NULL;
    ptr->ptrri = NULL;
    ptr->height = 1;
    return ptr;
}
void inordertraversal(struct node*ptr)
{
    if(ptr!=NULL)
    {
        inordertraversal(ptr->ptrlf);
        printf("\n%d",ptr->data);
        inordertraversal(ptr->ptrri);

    }
};
int getheight(struct node* n ){
    if(n==0){
        return 0;
    }
    return n->height;
}
int getbalancefactor(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getbalancefactor(n->ptrlf) - getbalancefactor(n->ptrri);
};
struct node *ptrlfRotate(struct node *x)
{
    struct node *y = x->ptrri;
    struct node *T2 = y->ptrlf;
 
    // Perform rotation
    y->ptrlf = x;
    x->ptrri = T2;
 
    //  Update heights
    x->height = max(height(x->ptrlf),  
                    height(x->ptrri)) + 1;
    y->height = max(height(y->ptrlf),
                    height(y->ptrri)) + 1;
 
    // Return new root
    return y;
};
struct node *ptrriRotate(struct node *y)
{
    struct node *x = y->ptrlf;
    struct node *T2 = x->ptrri;
 
    // Perform rotation
    x->ptrri = y;
    y->ptrlf = T2;
 
    // Update heights
    y->height = max(height(y->ptrlf),
                    height(y->ptrri)) + 1;
    x->height = max(height(x->ptrlf),
                    height(x->ptrri)) + 1;
 
    // Return new root
    return x;
};
struct Node* insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(maker(key));
 
    if (key < node->data)
        node->ptrlf  = insert(node->ptrlf, key);
    else if (key > node->data)
        node->ptrri = insert(node->ptrri, key);
    else // Equal datas are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->ptrlf),
                        height(node->ptrri));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // ptrlf ptrlf Case
    if (balance > 1 && key < node->ptrlf->data)
        return ptrriRotate(node);
 
    // ptrri ptrri Case
    if (balance < -1 && key > node->ptrri->data)
        return ptrlfRotate(node);
 
    // ptrlf ptrri Case
    if (balance > 1 && key > node->ptrlf->data)
    {
        node->ptrlf =  ptrlfRotate(node->ptrlf);
        return ptrriRotate(node);
    }
 
    // ptrri ptrlf Case
    if (balance < -1 && key < node->ptrri->data)
    {
        node->ptrri = ptrriRotate(node->ptrri);
        return ptrlfRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
 
//video name is binary tree: linked representation there you can find the tree only NULL is replace by 5
void main()
{
struct node *p,*p2l,*p2r,*p3ll,*p3lr,*p3rl,*p3rr,*test;
p = maker(5);
p2l = maker(3);                                                     
p2r = maker(7);                                         
p3ll = maker(2);
p3lr = maker(4);
p3rl = maker(6);
p3rr = maker(8);
p->ptrlf = p2l;
p->ptrri = p2r;
p2l->ptrlf = p3ll;
p2l->ptrri = p3lr;
p2r->ptrlf = p3rl;
p2r->ptrri = p3rr;



 

}
 