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
