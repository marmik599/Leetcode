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
    int getLength(ListNode* head) {
		ListNode* node = head;
		int length = 0;
		while (node != NULL) {
			length++;
			node = node->next;
		}
		return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k <= 1 || head == NULL) {
            return head;
        }

        ListNode* current = head;
        ListNode* prev = NULL;

		int length = getLength(head);
		int count = length / k;
        while (count > 0) {
            ListNode* last = prev;
            ListNode* newEnd = current;

            ListNode* next = current->next;
            for (int i = 0; current != NULL && i < k; i++) {
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

            prev = newEnd;
			count--;
        }
        return head;
    }

};