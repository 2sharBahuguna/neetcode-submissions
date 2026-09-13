# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return head
        curr= head
        pos=0
        while curr:
            curr=curr.next
            pos+=1
        
        target= pos-n

        if target == 0:
            return head.next

        curr=head
        prev=None
        i=0
        while i<target:
            prev=curr
            curr=curr.next
            i+=1
        
        prev.next=curr.next

        return head

        
