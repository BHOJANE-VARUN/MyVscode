#include<stdio.h>
#include<stdlib.h>
struct nodes
{
    int data;
    struct nodes *next;
};
void main()
{
//code goes here
 struct nodes *head, *insert, *first, *second, *midins;
    head = (struct nodes *)malloc(sizeof(struct nodes));
    first = (struct nodes *)malloc(sizeof(struct nodes));
    second = (struct nodes *)malloc(sizeof(struct nodes));
    head->data = 1;
    first->data = 2;
    second->data = 3;
    head->next = first;
    first->next = second;
    second->next = head;
    struct nodes *ptr = head;
    do
    {
     printf("%d",ptr->data); 
     ptr = ptr->next;  
    } while (ptr!=head);
    
    
    
}