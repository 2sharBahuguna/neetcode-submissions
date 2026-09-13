class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = 0
        fast = 0

        # Phase 1: find intersection
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]

            if slow == fast:
                break

        # Phase 2: find cycle entrance
        slow = 0

        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]

        return slow