#include <bits/stdc++.h> 
using namespace std;
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


void splitCircularList(Node *head)
{
    // Write your code here.
    Node * slow = head;
    Node * fast = head;
    Node * prev = NULL;
    while(slow!=NULL && fast!=NULL)
    {
        if(fast->next!=head)
        {
           fast = fast->next;
           prev = slow;
           slow = slow->next;
           if(fast->next!=head)
           {
               fast =fast->next;
           }
           else{
               break;
           }
        }
        else{
            // slow = slow ->next;
            break;
        }
    }
    fast->next =slow;
    prev->next = head;
}
int main()
{
    return 0;
}
