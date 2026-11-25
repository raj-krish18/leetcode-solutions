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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while(b != NULL){
            while(b != NULL && b->val == a->val){
                b = b->next; // move until found different
            }
            a->next = b; // join different node to node a
            a = b; // continue the process for next nodes
            if(b!= NULL) b = b->next;
            
        }
        return head;
    }
};