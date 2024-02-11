#include <iostream>
#include<map>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int num)
    {
        this->data = num;
        this->next = NULL;
    }
    void insertathead(node *&head, int num)
    {
        node *temp = new node(num);
        temp->next = head;
        head = temp;
    }
    void insertattail(node *&tail, int num)
    {
        node *temp = new node(num);
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
    void insertmiddle(node *tail, node *&head, int num, int pos)
    {
        if (pos == 1)
        {
            insertathead(head, num);
            return;
        }
        node *it = head;
        int i = 1;
        while (i < pos - 1)
        {
            it = it->next;
            i++;
        }
        if (it->next == NULL)
        {
            insertattail(tail, num);
            return;
        }
        node *temp = new node(num);
        temp->next = it->next;
        it->next = temp;
    }
    void del(int pos, node *&head, node *&tail)
    {
        node *temp = head;
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        if (i != 1)
        {
            node *ptr = temp->next;
            temp->next = ptr->next;
            delete ptr;
            if (temp->next == NULL)
            {
                tail = temp;
            }
        }
        else
        {
            node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }
};
void printlist(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
// void fix(node *&prev,node *&cur)
// {   if(cur==NULL) return;

//     node *temp = cur->next;
//     cur->next = prev;
//     prev = cur;
//     cur = temp;
//     fix(prev,cur);
// }
void reverseLinkedList(node *&head)
{
    int low = 1, high = 3;
    node *temp = head;
    int i = 0;
    while (i < low-1)
    {
        temp = temp->next;
        // cout<<temp->data<<endl;
        i++;
    }
    // node* cur = temp->next;
    node *prev = temp;
    node *cur = temp->next;
    node *l = cur;
    node *forw = NULL;
    int j =i+1;
    while (j < high)
    {
        forw = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forw;
        j++;
    }
    if (i == 0)
    {  
        //cout<<head->data<<endl;
        head->next = cur;
        head = prev;
        //cout<<head->data<<endl;
    }
    else
    {
        //prev->next = cur;
        temp->next = prev;
         l->next = cur;
    }
    
}
bool detectAndRemoveCycle(Node *head)
{	
    map<Node*,bool> mp;
    Node *prev=NULL;
    int flag = 0;
    while (head!=NULL)
    {
        if(mp[head]==true)
        {
            flag = 1;
            break;
        }
        mp[head]=true;
        prev = head;
        head = head->next;
    }
    if(flag)
    {
        prev->next = NULL;
        return flag;
    }
    else{
        return flag;
    }
}
int main()
{ // 1 3 2 4 6 5
    node *a = new node(3);
    node *head = a;
    node *tail = a;
    printlist(head);
    a->insertathead(head, 1);
    printlist(head);
    a->insertattail(tail, 2);
    a->insertattail(tail, 4);
    a->insertattail(tail, 6);
    printlist(head);
    // a->insertmiddle(tail,head,3,4);
    // printlist(head);
    // a->del(4,head,tail);
    // printlist(head);
    // reverseLinkedList(head);
    cout<<detectAndRemoveCycle(head);
    // printlist(head);

}