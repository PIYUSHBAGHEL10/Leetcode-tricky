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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        ListNode* temp = head;
        int n = 0 ;
        while(temp){
            n++;
            temp=temp->next;
        }
        for( int i=1 ; i<k ; i++){
            start=start->next;
        }
        for(int j=1 ; j<=n-k ; j++){
            end=end->next;
        }
        int val=start->val;
        start->val=end->val;
        end->val=val;


        return head;

    }
};