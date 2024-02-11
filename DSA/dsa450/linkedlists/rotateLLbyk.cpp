#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/
#include<iostream>
using namespace std;
class DLLNode {
    public:
	int data;
	DLLNode *next;
    DLLNode *prev;
	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};
DLLNode* rotateDLL(DLLNode* head, int k) 
{
    DLLNode* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
	int i =0;
	while(i<k)
	{
		temp = temp->next;
		i++;
	}
	 head =temp->next;
	temp->next = NULL;
	head->prev = NULL;
	return head;
}
int main()
{
    return 0;
}