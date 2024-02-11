#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
//hashmap approch
#include "unordered_map"
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{   if(head==NULL) return NULL;
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *> mp;
    LinkedListNode<int> * start = new LinkedListNode<int> (head->data);
    mp[head] = start;
    LinkedListNode<int> * temp = head->next;
    while(temp!=NULL)
    {
        start->next = new LinkedListNode<int> (temp->data);
        mp[temp] = start->next;
        start = start->next;
        temp = temp->next;
    }
    LinkedListNode<int> *again = head;
    LinkedListNode<int> *clone = mp[head];
    while(again!=NULL)
    {   if(again->random==NULL)
        {
            clone->random = NULL;
        }
        else
       clone->random = mp[again->random];
       clone = clone->next;
       again = again->next;
    }
    return mp[head];
}
//approch 2 
#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


*************************************************************/
 void insertAtTail(LinkedListNode<int>* &head, LinkedListNode<int>* &tail, int d) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{   //step 1: Create a Clone List
        LinkedListNode<int> *  cloneHead = NULL;
        LinkedListNode<int> *  cloneTail = NULL;

        LinkedListNode<int> *  temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }

        // step 2: insert nodes of Clone List in between originalList

        LinkedListNode<int> *  originalNode = head;
        LinkedListNode<int> *  cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL) {
            LinkedListNode<int> *  next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }

        // step 3: Random pointer copy
        originalNode = head;
          cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL) { 

            if(originalNode -> random != NULL) {
                cloneNode -> random = originalNode -> random -> next;
            }
            else
            {
                cloneNode -> random  = NULL;
            }

            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }

        //step 4: revert step 2 changes
        LinkedListNode<int> *  original = head;
        LinkedListNode<int> *  copy = cloneHead;

         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;

                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    
}

