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
//video name is binary tree: linked representation there you can find the tree only NULL is replace by 5
void main()
{
struct node *p,*p2l,*p2r,*p3ll,*p3lr,*p3rl,*p3rr;
p = maker(2);
p2l = maker(1);                                                     
p2r = maker(4);                                         
p3ll = maker(11);
p3lr = maker(12);
p3rl = maker(5);
p3rr = maker(3);
p->ptrlf = p2l;
p->ptrri = p2r;
p2l->ptrlf = p3ll;
p2l->ptrri = p3lr;
p2r->ptrlf = p3rl;
p2r->ptrri = p3rr;



 

}
 