Node*findPartiton(Node*head, int x)

{

    // Write your code here

    Node *lefttail=NULL;

    Node *lefthead=NULL;

    Node *righthead=NULL;

    Node *righttail=NULL;

    

    while(head!=NULL)

    {

        Node *temp=new Node(head->data);

        if(head->data<x)

        {

            if(lefthead==NULL)

            {

                lefthead=temp;

                lefttail=temp;

            }

            else{

                lefttail->next=temp;

                lefttail=lefttail->next;

            }

        } else {

             if(righthead==NULL)

            {

                righthead=temp;

                righttail=temp;

            }

            else{

                righttail->next=temp;

                righttail=righttail->next;

            }

        }

        head=head->next;

    }

    if(lefthead==NULL)

    {

        return righthead;

    }

    else{

        righttail=NULL;

        lefttail->next=righthead;

        return lefthead;

    }

}