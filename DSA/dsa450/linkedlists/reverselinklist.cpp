#include <bits/stdc++.h>
using namespace std;

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
// template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// template <typename T>
// class LinkedListNode
// {
// public:
//     T data;
//     LinkedListNode<T> *next;
//     LinkedListNode(T data)
//     {
//         this->data = data;
//         this->next = nullptr; // Using nullptr instead of NULL for modern C++
//     }
// };

// template <typename T>
// class LinkedList
// {
// public:
//     LinkedListNode<T> *head;

//     LinkedList()
//     {
//         head = nullptr;
//     }

//     void insert(T data)
//     {
//         LinkedListNode<T> *newNode = new LinkedListNode<T>(data);
//         if (!head)
//         {
//             head = newNode;
//         }
//         else
//         {
//             LinkedListNode<T> *temp = head;
//             while (temp->next)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }

//     void display()
//     {
//         LinkedListNode<T> *temp = head;
//         while (temp)
//         {
//             std::cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         std::cout << "nullptr" << std::endl;
//     }
// };
void fix(LinkedListNode<int> *&prev,LinkedListNode<int> *&cur)
{   if(cur==NULL) return;
    LinkedListNode<int> *temp = cur;
    cur->next = prev;
    fix(temp,temp->next);
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *&head) 
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *cur = head;
    fix(prev,cur);
    return prev;
}
int main()
{
    LinkedList<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    list.display();
    list.head = reverseLinkedList(list.head);
    list.display();
    return 0;
}