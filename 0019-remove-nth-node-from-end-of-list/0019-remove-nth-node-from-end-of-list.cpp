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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // int len = 0;
        // while (temp != nullptr) {
        //     temp = temp->next;
        //     len++;
        // }
        // if (len == n) {
        //     head = head->next;
        //     return head;
        // }
        // temp = head;
        // for (int i = 1; i < len - n; i++) {
        //     temp = temp->next;
        // }
        // temp->next = temp->next->next;
        // return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 1; i <=n+1; i++){
            if(fast == nullptr){
            head = head->next;
            return head;
            }
            fast = fast->next;
        }
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};