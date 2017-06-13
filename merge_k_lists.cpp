/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct ListNodeCmp {
          using T = ListNode*;
          bool operator()(const T& a, const T& b) const {
            return a->val < b->val;
          }
        };
        multiset<ListNode*, ListNodeCmp> ptrs; // always contains non-null ptr.
        for (auto l: lists) {
            if (l) {
                ptrs.insert(l);
            }
        }
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        while (!ptrs.empty()) {
            auto minPtrItr = ptrs.begin();
            ListNode* minPtr = *minPtrItr;
            // Append minPtr to the new list.
            if (!newHead) {
                newHead = newTail = new ListNode(minPtr->val);
            } else {
                newTail->next = new ListNode(minPtr->val);
                newTail = newTail->next;
            }

            ptrs.erase(minPtrItr);
            auto next = minPtr->next;
            if (next) {
                ptrs.insert(next);
            }
        }

        return newHead;
    }
};


