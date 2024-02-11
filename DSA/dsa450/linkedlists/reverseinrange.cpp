/********************************************************

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

********************************************************/
Node* rev(Node* node,int cnt)
{
	Node* cur=node;
	Node* prev=NULL;
	Node* nxt=NULL;
	while(cur && cnt)
	{
		nxt=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nxt;
		cnt--;
	}
	return prev;
}
Node *reverseLL(Node *head, int low, int high) 
{
	Node* prev=NULL;
	Node* nxt=NULL;
	Node* cur=NULL;
	Node* temp=head;
	int cnt=1;
	while(temp!=NULL)
	{
		if (cnt==low-1) prev=temp;
		if (cnt==high+1) nxt=temp;
		if (cnt==low) cur=temp;
		temp=temp->next;
		cnt++;
	}
	Node* node1=rev(cur,high-low+1);
	cur->next=nxt;
	if (prev)
	{
		prev->next=node1;
		return head;
	}
	return node1;
	
}
