class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }
        slow = head;
        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) {
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return nullptr;
    }
};