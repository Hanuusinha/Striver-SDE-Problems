//BY USING HASHING:
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

bool detectCycle(Node *head)
{
    if(head == NULL)
    {
        return false;
    }
    unordered_set<Node *> s;
    Node * temp = head;
    while(temp!= NULL)
    {
        if(s.find(temp) == s.end())
        {
            s.insert(temp);
            temp = temp->next;
        }else{
            return true;
        }
        
    }
    return false;
	//	Write your code here
}

//BY USING 2-POINTER'S APPROACH:

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

bool detectCycle(Node *head)
{
    //Using 2 pointers approach:
    if(head == NULL or head->next == NULL)
    {
        return false;
    }
    Node * slow = head;
    Node * fast = head;
    while(fast->next != NULL and fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
	//	Write your code here
}
