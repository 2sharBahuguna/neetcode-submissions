# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        group_prev = dummy

        while True:
            # 1. Check that k nodes exist (read-only walk)
            kth = group_prev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            next_group_start = kth.next
            group_tail = group_prev.next   # first node now, last node after reversal

            # 2. Reverse exactly k nodes
            prev, curr = next_group_start, group_tail
            while curr != next_group_start:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt

            # 3. Reconnect and advance
            group_prev.next = kth          # kth is the group's new head
            group_prev = group_tail
        
