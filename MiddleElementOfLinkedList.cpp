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
int countNodes(Node *head)
{
    int ans = 0;
    while(head != NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}
Node *findMiddle(Node *head) {
    // Write your code here
    int n = countNodes(head);
    int middle = (n/2)+1;
    
    Node *ptr = head;
    int tempCount = middle-1;
    while(tempCount != 0)
    {
        ptr=ptr->next;
        tempCount -=1;
    }
    return ptr;
    
}
