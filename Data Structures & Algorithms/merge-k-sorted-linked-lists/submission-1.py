# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq=[]

        for node in lists:
            
            while(node):
                pq.append(node.val)
                node=node.next
        pq.sort()
        ans=ListNode(0)
        curr=ans
        
        for val in pq:
            curr.next=ListNode(val)
            curr=curr.next

        return ans.next