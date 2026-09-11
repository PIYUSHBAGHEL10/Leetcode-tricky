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
    ListNode* reverselist(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverselist(l1);
        l2 = reverselist(l2);
        ListNode* dummy;
        ListNode* head;
        head = dummy = new ListNode(-1);
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        int carry = 0;
        while (l1 || l2) {
            int fval = l1 ? l1->val : 0;
            int sval = l2 ? l2->val : 0;

            int sum = fval + sval + carry;
            carry = sum/10;
            sum = sum%10;

            dummy->next = new ListNode(sum);
            dummy = dummy->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        if (carry)
            dummy->next = new ListNode(1);

        return reverselist(head->next); // o(max(m,n))
    }
};