/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{   Node* ans =NULL;
    Node* head =NULL;
    int carry =0;
    while(num1!=NULL && num2!=NULL)
    {
        int ele = num1->data+num2->data+carry;
        if(ans==NULL)
        {
            Node*temp =new Node(ele%10);
            ans = temp;
            head =ans;
            num1 = num1->next;
            num2 = num2->next;
        }
        else{
            Node*temp =new Node(ele%10);
            head->next = temp;
            head = temp;
            num1 = num1->next;
            num2 = num2->next;
        }
        
        carry = ele/10;
    }
    if(num1!=NULL || num2!=NULL)
    {
        Node* temp = num1==NULL?num2:num1;
        while(temp!=NULL)
        {
            int ele = temp->data+(carry);
            Node*noe =new Node(ele%10);
            head->next = noe;
            head = noe;
            temp = temp->next;
            carry = ele/10;
        }
    }
    while(carry)
    {

            Node*noe =new Node(carry%10);
            head->next = noe;
            head = noe;
            carry = carry/10;
    }
    return ans;
}
