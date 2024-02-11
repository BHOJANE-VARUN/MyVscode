/********************************************************************

    Following is the representation of the Singly Linked List node:

    class node{
        public:
            node* data;
            node * next;
            node(node* data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* sortTwoLists(node* first, node* second) {
    if (first == NULL && second == NULL) {
        return NULL;
    }
    if (first == NULL || second == NULL) {
        return first == NULL ? second : first;
    }

    node* head;
    node* lm;
    node* li;

    if (first->data > second->data) {
        head = second;
        lm = second;
        li = first;
    } else {
        head = first;
        lm = first;
        li = second;
    }
   
    node* prev1 = lm;
     lm = lm->next;
    node*temp = li->next  ;
    while (lm != NULL && li != NULL) {
        if (prev1->data <= li->data && lm->data >= li->data) {
            prev1->next    = li;
            temp = li->next   ;
            li->next   = lm;
            prev1 = li;
            li = temp;
        } else {
            prev1 = lm;
            lm = lm->next ;
        }
    }

    if (li != NULL && lm == NULL) {
        prev1->next    = li;
    }

    return head;
}
node *findMiddle(node *head) {
    // Write your code here
    node * slow = head;
    node * fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* mergeSort(node *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    node* mid = findMiddle(head);
    node* righa = mid->next;
    mid->next = NULL;
    node* left = mergeSort(head);
    node* right = mergeSort(righa);

    node* ans = sortTwoLists(left, right);
    return ans;
}
