#include<iostream>
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
bool detectCycle(Node *head){
	//	Write your code here.
	if(head->next==NULL)
	{
		return 0;
	}
	Node *slow = head;
	Node *fast = head;
	while(slow!=NULL && fast!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL)
		{
			fast = fast->next;
		}
		if(fast==slow)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
    return 0;
}