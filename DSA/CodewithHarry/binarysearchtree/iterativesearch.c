#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *ptrlf;
  struct node *ptrri;
  int data;

};
struct node* lterativesearch(struct node* root,int key)
{
    while (root!=NULL)
    {   
        if(root->data==key)
        {
            return root;
        }
        else if (root->data>key)
        {
            root = root->ptrri;

        }
        else
        {
            root = root->ptrlf;
        }
        
    }
    return  NULL;
    
}
void main()
{
//tree is not written in this file 

}