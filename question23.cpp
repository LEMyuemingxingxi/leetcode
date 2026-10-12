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
    ListNode* reverseList(ListNode* head) {
        // iterate
        ListNode* reversehead;
        ListNode* reversel = nullptr;
        
        while (head!=nullptr)
        {
            reversehead = head;
            head = head->next;
            reversehead->next = reversel;
            reversel = reversehead;
        }
        return reversel;

    }
};