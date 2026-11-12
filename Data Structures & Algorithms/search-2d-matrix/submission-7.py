class Solution:
    def searchMatrix(self, nums: List[List[int]], target: int) -> bool:
        n=len(nums)
        m=len(nums[0])

        left=0
        right=(n*m)-1

        while(left<=right):
            mid=(left+right)//2
            row=mid//m
            col=mid%m

            if nums[row][col]==target:
                return True

            elif nums[row][col]>target:
                right=mid-1

            else:
                left=mid+1

        return False