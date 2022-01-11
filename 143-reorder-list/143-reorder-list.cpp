/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* hs=reverse(slow);
        ListNode* hf=head;
        
        while(hf!=NULL && hs!=NULL)
        {
            ListNode* temp=hf->next;
            hf->next=hs;
            hf=temp;
            
            temp=hs->next;
            hs->next=hf;
            hs=temp;
        }
        
        if(hf!=NULL)
        {
            hf->next=NULL;
        }
        
        
    }
};