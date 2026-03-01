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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        if(slow==NULL || slow->next==NULL || fast->next->next==NULL) return false;

        do{
            slow=slow->next;
            fast=fast->next->next;
            if(fast==nullptr || fast->next==nullptr) return false;
        }
        while(slow!=fast);

        return true;
    }
};