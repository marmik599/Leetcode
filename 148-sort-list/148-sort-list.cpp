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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        // Merge two sorted lists
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        
        while(list1 and list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }
        
        // For unequal length LL
        temp->next = list1 != nullptr ? list1 : list2;
        
        return newHead->next;
    }
    
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast and fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        
        // Merge Sort
        if(head == nullptr || head->next == nullptr)
            return head;
        
        // Find the middle
        ListNode* middle = getMiddle(head);
        ListNode* list1 = head;
        ListNode* list2 = middle->next;
        middle->next = nullptr;
        
        // Sort both the lists
        list1 = sortList(list1);
        list2 = sortList(list2);
        
        // Merge two sorted list
        return merge(list1, list2);
    }
};