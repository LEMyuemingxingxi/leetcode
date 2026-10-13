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
ListNode* MergeTwoList(ListNode* a, ListNode* b){
    if ((!a)||(!b))
    {
        return a ? a : b;
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(a&&b){
        if(a->val < b->val){
            tail->next = a;
            a = a->next;
        }else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
}

ListNode* merge(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = merge(head);
    ListNode* right = merge(mid);
    return MergeTwoList(left, right);
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return merge(head);
    }
};