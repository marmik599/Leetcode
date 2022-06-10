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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* lessthan= new ListNode(0);
        ListNode* lth=lessthan;
        ListNode* greaterthan=new ListNode(0);
        ListNode* gth=greaterthan;
        
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                lessthan->next=curr;
                lessthan=lessthan->next;
            }
                
            else
            {
                greaterthan->next=curr;
                greaterthan=greaterthan->next;
            }
            
            curr=curr->next;
        }
        greaterthan->next=NULL;
        lessthan->next=gth->next;
        
        return lth->next;
        
        
    }
};