/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    auto reversedTail = head->next;
    auto reversedHead = reverse(head->next);
    reversedTail->next = head;
    head->next = nullptr;
    return reversedHead;
}

ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    int i = 1;
    ListNode* first = nullptr;
    ListNode* preFirst = nullptr;
    ListNode* last = nullptr;
    ListNode* ptr = A;
    ListNode* pre = nullptr;

    while (ptr) {
        if (m == i) {
            preFirst = pre;
            first = ptr;
        }
        if (n == i) {
            last = ptr;
        }
        pre = ptr;
        ptr = ptr->next;
        i++;
    }
    ListNode* tail = pre;

    ListNode* lastNext = last->next;
    last->next = nullptr;
    auto newHead = reverse(first);

    first->next = lastNext;
    if (preFirst) {
        preFirst->next = newHead;
        return A;
    }
    return newHead;

    ListNode* head = A;
    ListNode* reversed = nullptr;

    int cnt = 0;
    while (head) {
        ListNode* tmp = head->next;

        if (cnt )
        head->next = reversed;
        reversed = head;

        head = tmp;
    }

    return reversed;

}
