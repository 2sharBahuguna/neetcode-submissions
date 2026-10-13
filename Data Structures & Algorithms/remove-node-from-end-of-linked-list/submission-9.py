# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head
        curr=head
        cnt=0
        while(curr):
            cnt+=1
            curr=curr.next

        

        target=cnt-n

        if target==0:
            return head.next
        prev=None
        curr=head
        while(target>0):
            prev=curr
            curr=curr.next
            target-=1

        
        prev.next=curr.next

        

        return head