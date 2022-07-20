#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> * iter = head,*front = head;
    //STEP-1: CREATING AND ATTACHING ALL THE DUMMY NODES:
    while(iter != NULL)
    {
        front = iter->next;
        LinkedListNode<int> * copy = new LinkedListNode<int>(iter->data);
        copy->next = iter->next;
        iter->next = copy;
        iter = front;
    }
    //STEP-2: ASSIGNING ALL THE DUMMY NODES RANDOM POINTERS:
    iter = head;
    while(iter != NULL)
    {
        iter->next->random = iter->random;
        iter = iter->next->next;
    }
    //STEP->3: RESTORE THE COPY LIST:
    iter = head;
    LinkedListNode<int> * pseudoHead = new LinkedListNode<int>(1);
    LinkedListNode<int> * copy = pseudoHead;
    while(iter != NULL)
    {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
        
    }
    return pseudoHead->next;
    
    // Write your code here.
}
