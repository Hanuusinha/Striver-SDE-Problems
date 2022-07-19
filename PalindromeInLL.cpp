//BY USING EXTERNAL ARRAY:

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

bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> temp;
    LinkedListNode<int> * node = head;
    while(node != NULL)
    {
        temp.push_back(node->data);
        node = node->next;
    }
    vector<int> temp2(temp.begin(),temp.end());
    reverse(temp2.begin(),temp2.end());
    for(int i = 0 ; i < temp.size() ; i++)
    {
        if(temp[i] != temp2[i])
        {
            return false;
        }
    }
    return true;
    // Write your code here.

}
// USING 2-POINTERS APPROACH:

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
LinkedListNode<int> * reverse(LinkedListNode<int> *head){
    LinkedListNode<int> * curr=head;
    LinkedListNode<int> * prev=NULL;
    
    while(curr!=NULL){
        LinkedListNode<int> * n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        
    }
    
    return prev;
}


bool isPalindrome(LinkedListNode<int> *head) {
   
   // LinkedListNode<int> * newh=reverse(head);
    if(head==NULL){
        return true;
    }
    LinkedListNode<int> * slow=head;
    LinkedListNode<int> * fast=head->next;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    
    LinkedListNode<int> * newh=slow->next;
    slow->next=NULL;
    
    newh=reverse(newh);
    LinkedListNode<int> *temp=head;
    while(newh!=NULL && temp!=NULL){
        if(temp->data!=newh->data){
            return false;
        }
        newh=newh->next;
        temp=temp->next;
    }
    
    return true;
    
    
    
    
//     return true;

}
