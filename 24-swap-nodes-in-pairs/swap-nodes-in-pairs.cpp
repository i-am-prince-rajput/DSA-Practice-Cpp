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
    ListNode* swapPairs(ListNode* l) {
        if(l == NULL || l->next == NULL ){
            return l;
        }
        int temp=l->val;
        l->val=l->next->val;
        l->next->val=temp;
        swapPairs(l->next->next);
        return l;
    }
};