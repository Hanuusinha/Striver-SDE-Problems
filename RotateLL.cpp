#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    if(head == NULL or head->next == NULL)
    {
        return head;
    }
     // Write your code here.
    while(k--)
    {
        Node * temp1 = head;
        Node * temp2 = head;
        Node * temp3 = head;
        //Send temp2 to tail:
        while(temp3->next->next != NULL)
        {
            temp3 = temp3->next;
        }
        temp2 = temp3->next;
        temp3->next = NULL;
        temp2->next = temp1;
        head = temp2;
        
    }
    return head;
}

//USING OPTIMAL APPROACH:

#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    if(head == NULL or head ->next == NULL or k == 0)
    {
        return head;
    }
//     k = n%k;
    //Calculate the length of the LinkedList:
    int n = 1;
    Node * temp = head;
    while(temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }
    //Connect the last node to the first node:
    temp ->next = head;
    //Now goto (n - k)th node and break the node:
    Node * dummy = head;
     k = k%n;
    k = (n - k);
    while(--k)
    {
        dummy = dummy->next;
    }
    head = dummy->next;
    dummy->next = NULL;
    
    return head;
     // Write your code here.
}
