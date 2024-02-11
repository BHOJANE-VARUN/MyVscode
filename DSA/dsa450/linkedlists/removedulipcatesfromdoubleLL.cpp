#include<iostream>
using namespace std;
class Node {
  public:
      int data;
      Node *prev;
      Node *next;
      Node() {
          this->data = 0;
           this->prev = NULL;
         this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->prev = NULL;
          this->next = NULL;
       }
      Node (int data, Node *next, Node *prev) {
          this->data = data;
           this->prev = prev;
          this->next = next;
      }
 };
void removenode(Node* pre,Node* cur,Node* nex)
{
    pre->next = nex;
    nex->prev = pre;
    
    cur->next = NULL;
    cur->prev = NULL;
}
Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node * pre = head;
    Node * cur = head->next;
    Node * nex = cur->next;

    while(nex!=NULL)
    {
        if(pre->data==cur->data)
        {
            removenode(pre, cur, nex);
            cur = nex;
            nex = nex->next;
        }
        else{
            pre = pre->next;
            cur = cur->next;
            nex = nex->next;
        }
        
    }
    if(pre->data==cur->data)
    {
        pre->next = NULL;
    }
    return head;
}
int main()
{
    return 0;
}
