class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        nums.sort()
        count=1
        maxi=1
        for i in range(1,len(nums)):
            if(nums[i]-nums[i-1]==1):
                count+=1
                maxi=max(maxi,count)
            
            elif(nums[i]-nums[i-1]>1):
                count=1

        return maxi
        