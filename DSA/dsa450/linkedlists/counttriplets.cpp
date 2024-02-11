#include <bits/stdc++.h> 
/***************************************
 
    Following is the Node class already written.

    class Node 
    {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data) 
        {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node() 
        {
            if (next != NULL)
            {
                delete next;
            }
        }
    };
 
***************************************/
int solve(Node* &head,Node* &tail,int k)
{
    int ans=0;
    Node * start = head;
    Node * end = tail;


    while (start!=end && end->next!=start)
    {
        int sum = start->data + end->data;
        if (sum == k)
        {
            ans++;
            start = start->next;
            end = end->prev;
        }
        else if (sum < k)
        {
            start = start->next;
        }
        else
        {
            end = end->prev;
        }

    }
    return ans;
    
}
int countAllTripletSum(Node *head, int x)
{   if(head==NULL || head->next==NULL || (head->next)->next==NULL)
    {
        return 0;
    }
    Node* tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    Node* temp = head;
    int ans =0;
    while(temp!=NULL && temp->next!=tail)
    {
        int ele = temp->data;
        ans += solve(temp->next, tail, x-ele);
        temp = temp->next;
    }
    return ans;
}