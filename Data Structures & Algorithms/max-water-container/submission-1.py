class Solution:
    def maxArea(self, nums: List[int]) -> int:
        i=0
        j=len(nums)-1
        maxi=0
        while(i<j):
            height=j-i
            width=min(nums[i],nums[j])
            maxi=max(maxi,height*width)

            if nums[i]>nums[j]:
                j-=1
            else:
                i+=1

        return maxi