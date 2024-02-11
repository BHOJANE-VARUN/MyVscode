#include<iostream>
#include<vector>
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
           this -> data = data;
           this -> prev = prev;
           this -> next = next;
      }
  };
// void solve(vector<pair<int,int>> &ans,Node * start,Node * end,int k)
// {
//     while((start->data+end->data)<=k && start!=end)
//     {
//         if((start->data+end->data)==k)
//         {
//             ans.push_back({start->data,end->data});
//             start = start->next;
//         }
//         else{
//            start = start->next;
//         }
//     }
// }
// vector<pair<int, int>> findPairs(Node* head, int k)
// {   Node* temp = head;
//     vector<pair<int,int>> ans;
//     while(temp->next!=NULL)
//     {   
//         temp =temp->next;
//         if((temp->data+head->data)<=k)
//         {
//             solve(ans, head, temp, k);
//         }
//         else{
//             break;
//         }
//     }
//     return ans;
// }

#include <unordered_set>

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    Node * ptr1 = head;

    unordered_set<int> hash;

    // Traverse the linked list to the end.
    while (ptr1 != NULL)
    {
        int val = ptr1->data;
        if (hash.find(k - val) != hash.end())
        {
            ans.push_back(make_pair(val, k - val));
        }
        else
        {
            hash.insert(val);
        }

        ptr1 = ptr1->next;
    }

    return ans;
}
int main()
{
    return 0;
}