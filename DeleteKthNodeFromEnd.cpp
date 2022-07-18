//TRAVERSAL APPROACH:
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    //Side-cases:
    if(head == NULL or K == 0)
    {
        return head;
    }
    LinkedListNode<int>* curr = head;
    //Calculate the length of the linkedlist:
    int n = 0;
    while(curr!=NULL)
    {
        n++;
        curr = curr->next;
        
    }
     K = n-K+1;
    LinkedListNode<int>* prev = NULL;
    curr = head;
    while(K>1)
    {
        K--;
        prev = curr;
        curr = curr->next;
        
    }
    if(prev != NULL)
    {
        prev->next = curr->next;
    }else{
        head = head->next;
    }
    return head;
    
    
    // Write your code here.
}
//WITHOUT FINDING THE SIZE OF THE LINKEDLIST:
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    LinkedListNode<int> *start = new LinkedListNode<int>(1);
    LinkedListNode<int>* fast = start,*slow = start;
    start->next = head;
    if(head == NULL or K == 0)
    {
        return head;
    }
    for(int i = 1 ; i <= K ; ++i)
    {
        fast = fast->next;
    }
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    // Write your code here.
    return start->next;
}
