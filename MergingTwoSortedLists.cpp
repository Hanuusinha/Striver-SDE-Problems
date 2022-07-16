//Using external list:

#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL and second != NULL)
    {
        return second;
    }
    if(first != NULL and second == NULL)
    {
        return first;
    }
    if(first == NULL and second == NULL)
    {
        return NULL;
    }
    Node<int>* result = NULL;
    
    if(first->data <= second->data)
    {
        result = first;
        first = first->next;
    }else{
        result = second;
        second = second->next;
    }
    Node<int>* traversal = result;
    
    while(first != NULL and second != NULL)
    {
        Node<int>* temp = NULL;
        if(first->data <= second->data)
        {
            temp = first;
            first = first->next;
        }else{
            temp = second;
            second = second->next;
        }
        traversal->next = temp;
        traversal = traversal->next;
    }
    while(first != NULL)
    {
        Node<int>* temp = first;
        first = first->next;
        traversal->next = temp;
        traversal = traversal->next;
    }
    while(second != NULL)
    {
        Node<int>* temp = second;
        second = second->next;
        traversal->next = temp;
        traversal = traversal->next;
    }
    traversal->next = NULL;
    return result;
}
//Using recursive approach:
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)return second;
    if(second == NULL)return first;
    Node<int>* result = NULL;
    if(first->data<=second->data)
    {
        result = first;
        result->next = sortTwoLists(first->next,second);
        
    }else{
        result = second;
        result->next = sortTwoLists(first,second->next);
    }
    return result;
    // Write your code here.
}

