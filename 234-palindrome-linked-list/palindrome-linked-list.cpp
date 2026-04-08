class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = NULL;
        ListNode* second = slow;

        while(second != NULL){
            ListNode* next = second->next;
            second->next = first;
            first = second;
            second = next;
        }

        ListNode* temp = head;

        while(first != NULL){
            if(first->val != temp->val){
                return false;
            }
            temp = temp->next;
            first = first->next;
        }

        return true; 
    }
};