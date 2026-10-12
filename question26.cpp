
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        do{
            slow = slow->next;
            if(fast == nullptr) return NULL;
            fast = fast->next;
            if(fast == nullptr) return NULL;
            fast = fast->next;
        }while(fast!=slow)
        ListNode *ptr = head;
        while(ptr!=slow){
            ptr = ptr->next;
            slow = slow->next;
        }
        return ptr;
    }
};