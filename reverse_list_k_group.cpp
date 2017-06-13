/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* ptr = head;
        ListNode* lastTail = nullptr;
        ListNode* newHead = nullptr;
        while (ptr) {
            ListNode* tail = ptr;
            ListNode* reversed = nullptr;
            int cnt = 0;
            while (cnt < k && ptr) {
                ListNode* tmp = ptr->next;
                ptr->next = reversed;
                reversed = ptr;
                ptr = tmp;
                cnt++;
            }

            if (cnt == k) {
                if (lastTail) {
                    lastTail->next = reversed;
                } else {
                    newHead = reversed;
                }
                lastTail = tail;
            } else {
                lastTail->next = reverse(reversed);
            }
        }
        return newHead;
    }

    ListNode* reverse(ListNode* ptr) {
        ListNode* reversed = nullptr;
        while (ptr) {
            ListNode* tmp = ptr->next;
            ptr->next = reversed;
            reversed = ptr;
            ptr = tmp;
        }
        return reversed;
    }
};