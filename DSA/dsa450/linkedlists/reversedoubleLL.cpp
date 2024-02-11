#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{   
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node * start = head;
    while(temp!=start && start->prev!=temp)
    {
        swap(start->data,temp->data);
        start = start->next;
        temp = temp->prev;
    }
    return head;
}
//second approach in we swap the prev and next pointer O(N) complexity
Node* reverseDLL(Node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    
    Node * curr = head;
    Node * temp = NULL;

    // Traverse the linked list to the end
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev ;
    }

    head = temp->prev ;

    // New head of the modified list is returned
    return head;
}
int main()
{
    return 0;
}

