#include <bits/stdc++.h> 
using namespace std;
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL)
    return head;
    unordered_map<int,bool> vis;

    Node* pre=head,* cur=head;

    while(cur!=NULL) {

        if(vis[cur->data]) {

            pre->next = cur->next;

            cur = pre->next;

        }

        else {

            vis[cur->data] = true;

            pre=cur;

            cur=cur->next;

        }

    }

    return head;

 

}
int main()
{
    return 0;
}