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

int findIntersection(Node *firstHead, Node *secondHead)
{
    
    if(firstHead == NULL or secondHead == NULL)
    {
        return NULL;
    }
    Node * first = firstHead;
    Node * second = secondHead;
    while(first != second)
    {
        first = first==NULL?secondHead:first->next;
        second = second== NULL?firstHead:second->next;
    }
    if(first == NULL and second == NULL)
    {
        return -1;
    }
    return first->data;
    
    
    //Write your code here
}
