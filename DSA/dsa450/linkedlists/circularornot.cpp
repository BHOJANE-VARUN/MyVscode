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


bool circularLL(Node* head)
{
    // Write your code here
	Node* temp = head;
	if(temp->next==head)
	{
		return true;
	}
	if(temp->next==NULL)
	{
		return false;
	}
	temp = temp->next;
	while(temp!=NULL && temp!=head)
	{
		temp = temp->next;
	}
	if(temp==NULL)
	{
		return false;
	}
	else{
		return true;
	}
}
int main()
{
    return 0;
}
