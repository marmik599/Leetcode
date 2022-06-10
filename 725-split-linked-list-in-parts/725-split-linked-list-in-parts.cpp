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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode* dummy = head;
        vector<ListNode*> ans;
        int idx = 0;
        while(dummy)
        {
            idx++;
            dummy = dummy->next;
        }
        int cng = idx%k;
        dummy = head;
        if(idx <= k)
        {
            while(k != 0)
            {
                if(dummy)
                {
                    ListNode* ptr = dummy;
                    dummy=dummy->next;
                    ptr->next = NULL;
                    ans.push_back(ptr);
                }
                else
                {
                    ans.push_back(NULL);
                }
                k--;
            }
        }
        else
        {
            int more = idx%k;
            int elecnt = idx/k;
            int checker = elecnt;
            while(dummy)
            {
                if(more != 0)
                {
                    ans.push_back(dummy); 
                    while(checker--)
                    {
                        dummy = dummy->next;
                    }
                    ListNode* ptr = dummy;
                    dummy = dummy->next;
                    ptr->next = NULL;
                    more--;
                    checker = elecnt;
                }
                else
                {
                    ans.push_back(dummy);
                    checker -= 1; 
                    while(checker--)
                    {
                        dummy = dummy->next;
                    }
                    ListNode* ptr = dummy;
                    dummy = dummy->next;
                    ptr->next = NULL;
                    checker = elecnt;
                }
            }
        }
        return ans;
    }
};