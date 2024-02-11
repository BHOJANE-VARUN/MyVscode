#include <bits/stdc++.h> 
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
void reverselink(LinkedListNode<int>* &head) {

    LinkedListNode<int>* curr = head;

    LinkedListNode<int>* prev = NULL;

 

    while(curr != NULL) {

        LinkedListNode<int>* next = curr -> next;

        curr -> next = prev;

        prev = curr;

        curr = next;

    }

    head = prev;

}
/*****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/
LinkedListNode<int>* addOneToList(LinkedListNode<int> *head)
{
    reverselink(head);
    LinkedListNode<int>* cur = head;
    while (cur!=NULL)
    {
        if(cur->data==-1)
        {
            cur = cur->next;
            continue;
        }

        if(cur->data==9)
        {
            while(cur!=NULL && cur->data==9)
            {
                cur->data = 0;
                cur = cur->next;
            }
            if(cur==NULL)
            {
                LinkedListNode<int>* first = new LinkedListNode<int> (1);
                cur->next = first;
                break;
            }
            else{
                cur->data++;
                break;
            }
        }
        else{
            cur->data++;
            break;
        }
    }
    reverselink(head);
    return head;
}
int main()
{
    return 0;
}
