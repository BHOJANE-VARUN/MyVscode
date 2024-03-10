#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
    node()
    {
        data = 0;
        next = NULL;
    }
};
void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *insert(node *head, int data)
{
    if (head == NULL)
    {
        return (new node(data));
    }
    else
    {
        node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new node(data);
        return head;
    }
}
node* delet(node* head,int data)
{
    node* prev = NULL;
    node* save = head;
    while(head and head->data!=data)
    {
        prev = head;
        head = head->next;
    }
    if(head)
    {
        if(prev)
        {
            prev->next = head->next;
        } 
        else
        {
            save =  save->next;
        } 
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return save;
}
void update(node*head,int old,int cur)
{
    while(head and head->data!=old)
        head = head->next;
    if(head)
    {
        head->data = cur;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}
int main()
{
    node *head = NULL;
    head = insert(head, 1);
    head = insert(head, 2); 
    head = insert(head, 3);
    head = insert(head,4);
    head = insert(head,5);
    head = delet(head, 10);
    display(head);
    update(head,10,10);
    display(head);
}