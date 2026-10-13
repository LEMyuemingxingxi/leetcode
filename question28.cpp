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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyhead(0);
        ListNode* tail = &dummyhead;
        int front = 0;
        int value = 0;
        while(l1&&l2){
            value = l1->val+l2->val+front;
            if(value >= 10){
                front  = 1;
            }else{
                front = 0;
            }

            ListNode* node = new ListNode(value % 10);
            tail->next = node;
            tail = node;
            l1 = l1->next;
            l2 = l2->next; 
        }

        while(l1){
            value = l1->val+front;
            if(value >= 10){
                front  = 1;
            }else{
                front = 0;
            }

            ListNode* node = new ListNode(value % 10);
            tail->next = node;
            tail = node;
            l1 = l1->next;
        }

        while(l2){
            value = l2->val+front;
            if(value >= 10){
                front  = 1;
            }else{
                front = 0;
            }

            ListNode* node = new ListNode(value % 10);
            tail->next = node;
            tail = node;
            l2 = l2->next;
        }
        if (front) {
            tail->next = new ListNode(front);
            tail = tail->next;
        }
        return dummyhead.next;
    }
};