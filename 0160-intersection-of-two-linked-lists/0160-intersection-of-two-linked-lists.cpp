/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        int lenA = 0;
        while(temp != nullptr){
            lenA++;
            temp = temp->next;
        }
        temp = headB;
        int lenB = 0;
        while(temp != nullptr){
            lenB++;
            temp = temp->next;
        }
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        if(lenA > lenB){
            for(int i = 1; i <= lenA-lenB; i++){
                tempA = tempA->next;
            }
        }
        else if(lenA < lenB){
            for(int i = 1; i <= lenB-lenA; i++){
                tempB = tempB->next;
            }
        }
        while(tempA != NULL){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};