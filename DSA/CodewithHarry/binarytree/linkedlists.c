#include <stdio.h>
#include <stdlib.h>
struct nodes
{
    int data;
    struct nodes *next;
};
void inmid(struct nodes *ptr1, struct nodes *ptr2, struct nodes *ptr3)
{
    ptr1->next = ptr2;
    ptr2->next = ptr3;
};
void del(int n,struct nodes *head)
{   int a =n;
    struct nodes *ptr = head;
    int count = 0;
    while(count<a-2)
    {
      ptr = ptr->next;
    count +=1;
    };
    struct nodes *q = ptr->next;
    ptr->next = q->next;
    free(q);
    

};

void main()
{
    // code goes here
    struct nodes *head, *insert, *first, *second, *midins;
    head = (struct nodes *)malloc(sizeof(struct nodes));
    first = (struct nodes *)malloc(sizeof(struct nodes));
    second = (struct nodes *)malloc(sizeof(struct nodes));
    insert = (struct nodes *)malloc(sizeof(struct nodes));
    midins = (struct nodes *)malloc(sizeof(struct nodes));
    head->data = 1;
    first->data = 2;
    second->data = 3;
    insert->data = 0;
    insert->next = head;
    midins->data = 3;
    struct nodes *ptr = insert;
    head->next = first;
    first->next = second;
    second->next = NULL;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    };
   

}