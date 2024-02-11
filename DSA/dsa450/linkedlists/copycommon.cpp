#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};
      
Node* intersect_ll(Node* L1, Node *L2){

    // Write your code here
    Node* one = L1;
    Node* two = L2;
    Node* head =NULL;
    Node* cur=NULL;
    while(one!=NULL && two!=NULL)
    {
        if(one->data==two->data)
        {
            if(cur==NULL)
            {
                cur = one;
                head = cur;
                one = one->next;
                two = two->next;
            }
            else{
                cur->next = one;
                cur = cur->next;
                one = one->next;
                two = two->next;
            }
        }
        else if(one->data>two->data)
        {
            one = one->next;
        }
        else{
            two = two->next;
        }
    }
    if(cur!=NULL)
    cur->next = NULL;
    return head;
}
int main()
{
    return 0;
}