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
        ListNode* end=head;
        ListNode* st=head;

        int cnt=0;
        while(end->next!=nullptr){
            end=end->next;
            cnt++;
        }

        int toRemove=cnt-n;
        if(toRemove==-1) return head->next;
        else {
            for(int i=0;i<toRemove;i++){
                st=st->next;
            }
            st->next=st->next->next;
        }
        return head;
    }
};