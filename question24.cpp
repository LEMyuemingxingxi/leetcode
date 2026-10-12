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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, fast = head;
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;
        }
        ListNode* reversehead;
        ListNode* reversel = nullptr;
        
        while (slow!=nullptr)
        {
            reversehead = slow;
            slow = slow->next;
            reversehead->next = reversel;
            reversel = reversehead;
        }

        while (reversel!=nullptr)
        {
            if(reversel->val==head->val){
                reversel = reversel->next;
                head = head->next;
            }else{
                return false;
            }
        }
        return true;
    }
};