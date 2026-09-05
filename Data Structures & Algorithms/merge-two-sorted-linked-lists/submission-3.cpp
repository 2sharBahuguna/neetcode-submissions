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
        
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* ans= new ListNode(-1);
        ListNode* dummy=ans;

        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val<ptr2->val){
                dummy->next= new ListNode(ptr1->val);
                ptr1=ptr1->next;
            }
            else{
                dummy->next=new ListNode(ptr2->val);
                ptr2=ptr2->next;
            }
            dummy=dummy->next;
        }

        while(ptr1!=NULL){
            dummy->next=new ListNode(ptr1->val);
            ptr1=ptr1->next;
            dummy=dummy->next;
        }

        while(ptr2!=NULL){
            dummy->next=new ListNode(ptr2->val);
            ptr2=ptr2->next;
            dummy=dummy->next;
        }

        return ans->next;
    }
};
