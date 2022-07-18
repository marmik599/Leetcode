/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* res=head;
        while(head!=NULL)
        {
            Node* temp=new Node(head->val);
            temp->next=head->next;
            head->next=temp;
            head=head->next->next;
        }
        head=res;
        
        while(head!=NULL)
        {
            if(head->random!=NULL)
            {
                head->next->random=head->random->next;
            }
            head=head->next->next;
        }
        head=res;
        Node* ans=new Node(0);
        Node* copy=ans;
        Node* start;
        while(head!=NULL)
        {
            start=head->next->next;
            ans->next=head->next;
            
            head->next=head->next->next;
            ans=ans->next;
            head=start;
        }
        return copy->next;
    }
};