#include <bits/stdc++.h> 
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

Node *firstNode(Node *head)
{
    if(head == NULL or head->next == NULL)
    {
        return NULL;
    }
    Node * slow = head,*fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast != NULL and fast -> next != NULL)
    {
        if(slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast)
    {
        return NULL;
    }
    slow = head;
    while(slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
        
	//    Write your code here.
    return fast;
}
