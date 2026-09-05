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
        if(head==NULL)    return NULL;
        int size=0;
        ListNode* ptr=head;

        while(ptr!=NULL){
            ptr=ptr->next;
            size++;
        }
        int position=0;
        if(size==n){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;   
        }
        position=size-n;

        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(position--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
        delete curr;

        return head;
    }
};
