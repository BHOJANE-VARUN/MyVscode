// /************************************************************

//     Following is the linked list node structure

//     template <typename T>
//     class Node {
//         public:
//         T data;
//         Node* next;

//         Node(T data) {
//             next = NULL;
//             this->data = data;
//         }

//         ~Node() {
//             if (next != NULL) {
//                 delete next;
//             }
//         }
//     };

// ************************************************************/
// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
//     if (first == NULL && second == NULL) {
//         return NULL;
//     }
//     if (first == NULL || second == NULL) {
//         return first == NULL ? second : first;
//     }

//     Node<int>* head;
//     Node<int>* lm;
//     Node<int>* li;

//     if (first->data > second->data) {
//         head = second;
//         lm = second;
//         li = first;
//     } else {
//         head = first;
//         lm = first;
//         li = second;
//     }
   
//     Node<int>* prev1 = lm;
//      lm = lm->next;
//     Node<int>*temp = li->next;
//     while (lm != NULL && li != NULL) {
//         if (prev1->data <= li->data && lm->data >= li->data) {
//             prev1->next = li;
//             temp = li->next;
//             li->next = lm;
//             prev1 = li;
//             li = temp;
//         } else {
//             prev1 = lm;
//             lm = lm->next;
//         }
//     }

//     if (li != NULL && lm == NULL) {
//         prev1->next = li;
//     }

//     return head;
// }
// Node<int> *solve(vector<Node<int>*> &arr,int cur,Node<int>*head)
// {   
//     if(cur==arr.size())
//     {
//         return head;
//     }
//     Node<int> *nhead = sortTwoLists(head, arr[cur]);
//     return solve(arr, cur+1, nhead);
// }
// Node<int>* mergeKLists(vector<Node<int>*> &listArray)
// {
//     // Write your code here.
//     if(listArray.size()==0) return NULL;
//     if(listArray.size()==2)
//     {
//         return sortTwoLists(listArray[0], listArray[1]);
//     }
//     if(listArray.size()<2)
//     {
//         return listArray[0];
//     }
//     Node<int>* head=sortTwoLists(listArray[0],listArray[1]);
//     return solve(listArray, 2, head);
// }
#include<queue>

class compare{

    public:

        bool operator()(Node<int>* a,Node<int>* b) {

            return a->data > b->data;

        }

};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)

{

    priority_queue <Node<int>*,vector<Node<int>*>,compare > pq; //min heap

    int n = listArray.size();

    for(int i=0;i<n;i++) {

        if(listArray[i] != NULL) {

            pq.push(listArray[i]);

        }

    }

    Node<int>* head=NULL,* tail=NULL;

    while(!pq.empty()) {

        Node<int>* tmp = pq.top();

        pq.pop();

        if(head==NULL) {

            head=tail=tmp;

        }

        else {

            tail->next = tmp;

            tail = tmp;

        }

        if(tail->next != NULL) {

                pq.push(tail->next);

        }

    }

    return head;

}