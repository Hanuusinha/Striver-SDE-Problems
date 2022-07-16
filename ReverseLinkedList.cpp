#include <bits/stdc++.h> 
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
//Iterative Approach:

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    
    LinkedListNode<int> *newHead = NULL;
    while(head != NULL)
    {
        LinkedListNode<int>* nextPtr = head;
        nextPtr = head->next;
        head->next = newHead;
        newHead = head;
        head = nextPtr;
     }
    head = newHead;
    return head;
    
}

//Recursive Approach:

#include <bits/stdc++.h> 
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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *nnode = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
    
}
