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
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* ans= new ListNode(-1);
        ListNode* node=ans;
        while(p1!=NULL && p2!=NULL){
            if(p1->val <= p2->val){
                node->next=p1;
                p1=p1->next;
            }
            else{
                node->next=p2;
                p2=p2->next;
            }
            node=node->next;
        }

        if(p1!=NULL) node->next=p1;
        if(p2!=NULL) node->next=p2;

        return ans->next;
    }
};
