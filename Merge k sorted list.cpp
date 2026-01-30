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
    // Custom comparator for min heap
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // smaller value = higher priority
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Step 1: push head of each list
        for (ListNode* head : lists) {
            if (head != nullptr)
                pq.push(head);
        }

        // Dummy node to simplify list construction
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Step 2: process heap
        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != nullptr)
                pq.push(curr->next);
        }

        return dummy.next;
    }
};
