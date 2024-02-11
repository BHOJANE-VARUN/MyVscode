/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is number of nodes in the linked list.
*/

Node* sortList(Node *head)
{
    Node* lists[3] = {}, *tails[3] = {};

    // Iterate while head is not empty node
    while(head)
    {
        Node *next = head->next;
        head->next = lists[head->data];
        lists[head->data] = head;

        if(tails[head->data] == NULL)
        {
            tails[head->data] = head;
        }
        
        head = next;
    }

    // Reconnecting
    if(lists[0])
    {
        if(lists[1])
        {
            tails[0]->next = lists[1];
            tails[1]->next = lists[2];
        }
        else
        {
            tails[0]->next = lists[2];
        }

        return lists[0];
    }

    // If lists[1] is not an empty node
    if(lists[1])
    {
        tails[1]->next = lists[2];
        return lists[1];
    }
    
    return lists[2];
}
