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
    ListNode* merge(ListNode* l1,ListNode *l2)
    {
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        ListNode* head=new ListNode(0);
        ListNode* res=head;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                head->next=l1;
                head=head->next;
                l1=l1->next;
            }
            else
            {
                head->next=l2;
                head=head->next;
                l2=l2->next;
            }
        }
        if(l1!=NULL)
        {
            head->next=l1;
        }
        if(l2!=NULL)
        {
            head->next=l2;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==1)
            return lists[0];
        if(lists.size()==0)
            return NULL;
        // ListNode* l1=lists[0];
        // ListNode* l2=lists[1];
        // ListNode* root=merge(l1,l2);
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++)
        {
             ans=merge(ans,lists[i]);
        }
        return ans;
    }
};