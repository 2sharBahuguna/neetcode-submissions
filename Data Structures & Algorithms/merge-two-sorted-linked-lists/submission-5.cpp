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
        if(list1==NULL && list2==NULL) return NULL;
        if(list1==NULL ) return list2;
        if(list2==NULL) return list1;

        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* ans= new ListNode(-1);
        ListNode* dummy= ans;
        while(ptr1!=NULL && ptr2!=NULL){
            int value= 0;
            if(ptr1->val>=ptr2->val){
                value= ptr2->val;
                ptr2=ptr2->next;
            }
            else{
                value=ptr1->val;
                ptr1=ptr1->next;
            }
            dummy->next= new ListNode(value);
            dummy=dummy->next;
        }

        while(ptr1!=NULL){
            dummy->next= new ListNode(ptr1->val);
            dummy=dummy->next;
            ptr1=ptr1->next;
        }

        while(ptr2!=NULL){
            dummy->next= new ListNode(ptr2->val);
            dummy=dummy->next;
            ptr2=ptr2->next;
        }
        
        return ans->next;
    }
};
