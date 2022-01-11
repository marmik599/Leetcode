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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (left == right) {
            return head;
        }

        // skip the first left-1 nodes
        ListNode* current = head;
        ListNode* prev = NULL;
        for (int i = 0; current != NULL && i < left - 1; i++) {
            prev = current;
            current = current->next;
        }

        ListNode* last = prev;
        ListNode* newEnd = current;

        // reverse between left and right
        ListNode* next = current->next;
        for (int i = 0; current != NULL && i < right - left + 1; i++) {
            current->next = prev;
            prev = current;
            current = next;
            if (next != NULL) {
                next = next->next;
            }
        }

        if (last != NULL) {
            last->next = prev;
        } else {
            head = prev;
        }

        newEnd->next = current;
        return head;
    }

        
    
};