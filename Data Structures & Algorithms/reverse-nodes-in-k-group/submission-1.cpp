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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;

        int size=0;
        ListNode* curr= head;
        while(curr!=NULL){
            curr=curr->next;
            size++;
        }

        if(size<k) return head;

        int count=0;
        ListNode* prev= NULL;
        ListNode* fwd=NULL;
        curr=head;

        while(curr!=NULL && count<k){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
            count++;
        }

        if(fwd!=NULL){
            head->next=reverseKGroup(fwd,k);
        }
        return prev;
    }
};
