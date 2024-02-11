#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *findMiddle(Node *head) {
    // Write your code here
    Node * slow = head;
    Node * fast = head;
    while(slow!=NULL && fast!=NULL)
    {
        if(fast->next!=NULL)
        {
           fast = fast->next->next;
           slow = slow->next;
        }
        else{
            // slow = slow ->next;
            break;
        }
    }
    return slow;
}
int main()
{
    return 0;
}