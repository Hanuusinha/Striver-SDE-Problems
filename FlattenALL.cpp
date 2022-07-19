#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node * merge(Node * a , Node * b)
{
    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }
    Node * ans;
    if(a->data<b->data)
    {
        ans = a;
        ans->child = merge(a->child,b);
    }else{
        ans = b;
        ans->child = merge(a,b->child);
    }
    ans->next = NULL;
    return ans ;
}
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL or head->next == NULL)
    {
        return head;
    }
    return merge(head,flattenLinkedList(head->next));
	// Write your code here
}
