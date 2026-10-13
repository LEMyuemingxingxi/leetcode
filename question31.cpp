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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyhead(0);
        dummyhead.next = head;
        ListNode* groupPrev = &dummyhead;

        while (head) {
            ListNode* check = head;
            int cnt = 0;
            for (int i = 0; i < k && check; ++i) {
                check = check->next;
                ++cnt;
            }

            if (cnt != k) {
                groupPrev->next = head;
                break;
            }

            ListNode* groupNext = check;

            ListNode* prev = nullptr;
            ListNode* cur  = head;
            for (int i = 0; i < k; ++i) {
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            groupPrev->next = prev;
            head->next = groupNext;
            groupPrev = head;
            head = groupNext;
        }

        return dummyhead.next;
    }
};
