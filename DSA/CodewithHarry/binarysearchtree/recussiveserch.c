/*binary tree is a tree in which one node is connected to only 1 or 2 or null nodes*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *ptrlf;
  struct node *ptrri;
  int data;

};
struct node* maker(int dat)
{
    struct node*ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = dat;
    ptr->ptrlf = NULL;
    ptr->ptrri = NULL;
    return ptr;
}
struct node * recsearch(struct node* ptr,int key)
{
    if(ptr!=NULL)
    {
        if(key==ptr->data)
        {
            return ptr;
        }
        else if(ptr->data>key)
        {
            return recsearch(ptr->ptrlf,key);
        }
        else 
        {
            return recsearch(ptr->ptrri,key);
        }
        
    }
    else{
        printf("key is not found in the BST");
        return NULL;
    }
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
test = recsearch(p,23);
}
 