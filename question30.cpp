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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyhead(0);
        dummyhead.next = head;
        if (head==nullptr||head->next==nullptr) return head;
        ListNode* prev = &dummyhead;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(1){
            slow->next = fast->next;
            fast->next = slow;
            prev->next = fast;
            if(slow->next==nullptr||slow->next->next==nullptr){
                break;
            }else{
                prev = prev->next->next;
                slow = prev->next;
                fast= slow->next;
            }
        }

        return dummyhead.next;
    }
};