#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL && second == NULL) {
        return NULL;
    }
    if (first == NULL || second == NULL) {
        return first == NULL ? second : first;
    }

    Node<int>* head;
    Node<int>* lm;
    Node<int>* li;

    if (first->data > second->data) {
        head = second;
        lm = second;
        li = first;
    } else {
        head = first;
        lm = first;
        li = second;
    }
   
    Node<int>* prev1 = lm;
     lm = lm->next;
    Node<int>*temp = li->next;
    while (lm != NULL && li != NULL) {
        if (prev1->data <= li->data && lm->data >= li->data) {
            prev1->next = li;
            temp = li->next;
            li->next = lm;
            prev1 = li;
            li = temp;
        } else {
            prev1 = lm;
            lm = lm->next;
        }
    }

    if (li != NULL && lm == NULL) {
        prev1->next = li;
    }

    return head;
}

