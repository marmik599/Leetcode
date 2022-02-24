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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
        {
            return l1;
        }
        ListNode* revhead1=reverse(l1);
        ListNode* revhead2=reverse(l2);
        
        ListNode* temp1=revhead1;
        ListNode* temp2=revhead2;
        
        int carry=0;
        ListNode* dummy=new ListNode();
        ListNode* head=dummy;
        while(temp1!=NULL || temp2!=NULL || carry)
        {
            int sum=0;
            if(temp1!=NULL)
            {
                sum=sum+temp1->val;
                temp1=temp1->next;
                
            }
            
            if(temp2!=NULL)
            {
                sum=sum+temp2->val;
                temp2=temp2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            ListNode* sumnode=new ListNode(sum%10);
            head->next=sumnode;
            head=head->next;
            
                
        }
        return reverse(dummy->next);
        
            
        
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};