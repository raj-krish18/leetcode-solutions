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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL  || head->next == NULL || k == 0) return head;
        ListNode* temp = head;
        int len = 0;
        ListNode* tail;
        while(temp != NULL){
            tail = temp;
            temp = temp->next;
            len++;
        }
        if(k >= len){
            k = k % len;
        }
        if(k==0) return head;
        temp = head;
        for(int i = 1; i <= len-k-1; i++){
            temp = temp->next;
        }
        ListNode *newhead = temp->next;
        tail->next = head;
        temp->next = NULL;
        return newhead;

    }
};