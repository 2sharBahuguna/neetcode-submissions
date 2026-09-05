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
        if(head==NULL) return head;

        int size=0;
        ListNode* curr=head;

        while(curr!=NULL){
            size++;
            curr=curr->next;
        }

        curr=head;

        if(size<n){
            return head;
        }

        else if(size==n){
            return head->next;
        }
        
        int toDel= size-n;
        ListNode* prev=NULL;
        while(toDel--){
            prev=curr;
            curr=curr->next;
        }   

        if(curr->next!=NULL){
            prev->next=curr->next;
        }
        else{
            prev->next=NULL;
        }

        return head;

        
    }
};
