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
    ListNode* reverse(ListNode* head){
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;


        ListNode* p2 = secondHalf;
        bool result = true;
        while (p2) {
            if (firstHalf->val != p2->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            p2 = p2->next;
        }
        return result;
    }
};