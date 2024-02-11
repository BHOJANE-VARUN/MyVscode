/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *child;
 * 		Node *child;
 *		Node() : data(0), child(nullptr), child(nullptr){};
 *		Node(int x) : data(x), child   (nullptr), child   (nullptr) {}
 *		Node(int x, Node *child, Node *child   ) : data(x), child (child   ), child   (child ) {}
 * };
 */
Node* sortTwoLists(Node* first, Node* second) {
    if (first == NULL && second == NULL) {
        return NULL;
    }
    if (first == NULL || second == NULL) {
        return first == NULL ? second : first;
    }

    Node* head;
    Node* lm;
    Node* li;

    if (first->data > second->data) {
        head = second;
        lm = second;
        li = first;
    } else {
        head = first;
        lm = first;
        li = second;
    }
   
    Node* prev1 = lm;
     lm = lm->child;
    Node*temp = li->child  ;
    while (lm != NULL && li != NULL) {
        if (prev1->data <= li->data && lm->data >= li->data) {
            prev1->child    = li;
            temp = li->child   ;
            li->child   = lm;
            prev1 = li;
            li = temp;
        } else {
            prev1 = lm;
            lm = lm->child ;
        }
    }

    if (li != NULL && lm == NULL) {
        prev1->child    = li;
    }

    return head;
}
Node* flattenLinkedList(Node* head) 
{   //base case
	if(head==NULL || head->next==NULL)
    {
        return head;
    }

    //recusive call
    Node* down = head;
    Node* secon = flattenLinkedList(head->next);
    down->next = NULL;
    //merge two sort LL
    Node* ans = sortTwoLists(down, secon);
    return ans;
}
