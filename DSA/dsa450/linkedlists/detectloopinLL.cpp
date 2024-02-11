#include <bits/stdc++.h>
using namespace std;
/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/
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
bool detectAndRemoveCycle(Node *head)
{
    unordered_map<int, int> mp;
    mp.insert({head->data,1});
    int flag = 1;
    while (head->next!=NULL)
    {
        if(mp.find((head->next)->data)!=mp.end())
        {
            flag = 0;
            break;
        }
        mp.insert(make_pair((head->next)->data,1));
        head = head->next;

    }
    if(flag)
    {
        head->next = NULL;
        return flag;
    }
    else{
        return flag;
    }
}
//by fast & slow pointers
/////////////////////////////////////////////////
Node* detectCycle(Node *head){
	//	Write your code here.
	if(head->next==NULL)
	{
		return NULL;
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
			return fast;
		}
	}
	return NULL;
}
bool detectAndRemoveCycle(Node *head)
{	
    Node* point = detectCycle(head);
    if(point==NULL)
    {
        return false;
    }
    else if(point==head)
    {
        while(point->next!=head)
        {
            point = point->next;

        }
        point->next = NULL;
        return true;
    }
    else{
        Node* slow = head;
        while(slow->next!=point->next)
        {
            slow = slow->next;
            point = point->next;
        }
        point->next = NULL;
        return true;
    }
}
//////////////////////////////////////////////////////////////
int main()
{
    return 0;
}
