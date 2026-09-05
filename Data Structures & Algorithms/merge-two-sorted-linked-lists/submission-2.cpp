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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2!=NULL) return list2;
        if(list2==NULL && list1!=NULL) return list1;
        if(list1==NULL && list2==NULL) return NULL;

        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* ans=new ListNode(-1);
        ListNode* curr= ans;
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1->val<=ptr2->val){
                curr->next=new ListNode(ptr1->val);
                ptr1=ptr1->next;
            }
            else if(ptr2->val<ptr1->val){
                curr->next=new ListNode(ptr2->val);
                ptr2=ptr2->next;
            }
            curr=curr->next;
        }

        while(ptr1!=NULL){
            curr->next= new ListNode(ptr1->val);
            ptr1=ptr1->next;
            curr=curr->next;
        }

        while(ptr2!=NULL){
            curr->next= new ListNode(ptr2->val);
            ptr2=ptr2->next;
            curr=curr->next;
        }
        
        return ans->next;
    }
};
