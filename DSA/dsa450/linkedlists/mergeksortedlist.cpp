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
#include<iostream>
#include<queue>
using namespace std;
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
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    if(listArray.size()==0) return NULL;
    if(listArray.size()<2)
    {
        return listArray[0];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0;i<listArray.size();i++)
    {
        Node* temp = listArray[i];
        while(temp!=NULL)
        {
            pq.push(temp->data); 
        }
    }
    Node<int>* head=NULL;
    Node<int>* temp = NULL;
    while (!pq.empty())
    {
        if(temp==NULL)
        {
            Node<int>* node = new Node<int>(pq.top());
            pq.pop();
            temp = node;
            head = temp;
        }
        else{
            Node<int>* node = new Node<int>(pq.top());
            pq.pop();
            temp->next = node;
            temp = node;
        }
    }
    return head;
}
