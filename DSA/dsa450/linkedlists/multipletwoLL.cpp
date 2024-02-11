/*
    Time Complexity: O(N*M)
    Space Complexity: O(N+M)
    
    Where N and M are the number of nodes in the first and the second linked list respectively.

*/

// Reverses the linked list and returns length of the list
int reverse(Node **head){
	Node *prev  = NULL;
	Node *curr = *head;
	int len = 0;
	
	while(curr != NULL){
		
		len++;
		Node *ahead = curr->next;
		curr->next = prev;
		prev = curr;
		curr = ahead;
		 
	}
	
	*head = prev;
	return len;
}

Node *makeEmptyList(int length)  
{  
    Node *head = NULL; 
	Node *traverse = NULL; 
	
    while (length--){
    	
    	Node * temp = new Node(0);
    	if(head == NULL){
    		head = temp;
    		traverse = temp;
		}
		else{
			
			traverse->next = temp;
			traverse = traverse->next;
			
		}
	}  
   
    return head;  
}  
   
Node *multiplyLL(Node *head1, Node *head2){
	
    // Reverse the input lists and get their lengths 
    int m = reverse(&head1), n = reverse(&head2);  
  
    // Make a list that will contain the result of multiplication, m+n+1 can be max size of the list  
    Node *result = makeEmptyList(m + n);  
  
    // Pointers for traversing the linked lists  
    Node *secondPtr = head2, *resultPtr1 = result, *resultPtr2, *firstPtr;  
  
    // multiply each Node of second list with first  
    while (secondPtr != NULL) {  
  
        int carry = 0;  
  
        // Each time we start from the next of Node from which we started last time  
        resultPtr2 = resultPtr1;  
  
        firstPtr = head1;  
  
        while (firstPtr != NULL) {  
  
            // Multiply first list's digit with current second list's digit  
            int mul = firstPtr->data * secondPtr->data + carry;  
  
            // Assign the product to corresponding Node of result  
            resultPtr2->data += mul % 10;  
  
            // Resultant Node itself can have more than 1 digit  
            carry = mul / 10 + resultPtr2->data / 10;  
            resultPtr2->data = resultPtr2->data % 10;  
  
            firstPtr = firstPtr->next;  
            resultPtr2 = resultPtr2->next;  
        }  
  
        // If carry is remaining from last multiplication  
        if (carry > 0) {  
            resultPtr2->data += carry;  
        }  
  
        resultPtr1 = resultPtr1->next;  
        secondPtr = secondPtr->next;  
        
    } 
	// reverse the result list  
    reverse(&result);  
	
	// Remove if there are zeros at starting  
    while (result->next != NULL && result->data == 0) {  
        Node* temp = result;  
        result = result->next;  
        free(temp);  
    }    
  
    // Return head of multiplication list  
    return result;  
    
}
