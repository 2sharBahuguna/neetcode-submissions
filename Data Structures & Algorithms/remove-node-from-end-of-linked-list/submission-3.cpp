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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int cnt=0;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }

        if(cnt<k){
            return head;
        }


        if (cnt == k) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }


        int pos=cnt-k;
        curr=head;
        ListNode* prev=head;
        while(pos--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

        return head;

    }
};
