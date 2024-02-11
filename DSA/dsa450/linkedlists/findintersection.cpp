/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include<iostream>
using namespace std;
 class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };
#include "unordered_map"
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_map<Node*,int> mp;
    Node * first = firstHead;
    while(first!=NULL)
    {
        mp[first] = first->data;
        first = first->next;
    }
    Node* second = secondHead;
    while(second!=NULL)
    {
        if(mp.find(second)!=mp.end())
        {
            return second;
        }
        else{
            second = second->next;
        }
    }
    return NULL;
}
int main()
{
    return 0;
}
