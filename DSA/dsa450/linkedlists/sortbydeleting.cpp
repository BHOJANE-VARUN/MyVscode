#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
void reverse(LinkedListNode<int> *&head)
    {
        // Initialize current, previous and next pointers
        LinkedListNode<int> * current = head;
        LinkedListNode<int> *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
LinkedListNode<int> * deleteNodes(LinkedListNode<int> * head) {
    // Write your code here
    if(head->next==NULL)
    {
        return head;
    }
    reverse(head);
    LinkedListNode<int>* cur = head;
    LinkedListNode<int>* front = head->next;
    while(front!=NULL)
    {
            if(front->data>=cur->data)
            {
                
                cur =cur->next;
                front =front->next;
            }
            else{
                cur->next = front->next;
                front = front->next;
            }
        
    }
    reverse(head);
    return head;
}