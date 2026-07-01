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
    bool isPalindrome(ListNode* head) {

        stack<int> st;

        int size=0;
        ListNode* temp=head;

        while(temp){
            size++;
            temp=temp->next;
        }

        bool odd=false;
        if(size%2==1) odd=true;

        int half=size/2;

        for(int i=0;i<half;i++){
            st.push(head->val);
            head=head->next;
        }
        if(odd) head=head->next;

        while(head){
            if(head->val==st.top()){
                st.pop();
            }else{
                return 0;
            }
            head=head->next;
        }

        return 1;

    }
};