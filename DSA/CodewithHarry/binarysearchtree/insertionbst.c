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
};
int insert(struct node* root,int key)
{
    struct node* tra,*n;

   while(root!=NULL)
   {
    tra = root;
    if (root->data==key)
    {
     printf("element is already present"); 
     return 0;  
    }
    else if(root->data>key)
    {
    
      root = root->ptrlf;
     

    }
    else
    {
      root = root->ptrri;
              

    }
   }
   n = maker(key);
  if (tra->data>key)
  {
    tra->ptrlf = n;
  }
  else 
  {
    tra->ptrri = n;
  }
  
  
}
void inordertraversal(struct node*ptr)
{
    if(ptr!=NULL)
    {
        inordertraversal(ptr->ptrlf);
        printf("\n%d",ptr->data);
        inordertraversal(ptr->ptrri);

    }
}
void main()
{struct node *p,*p2l,*p2r,*p3ll,*p3lr,*p3rl,*p3rr,*test;
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
insert(p,10);
insert(p,9);

inordertraversal(p);


//code goes here

}