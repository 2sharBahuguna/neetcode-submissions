class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp={}

        for i in range(len(nums)):
            compli= target-nums[i]

            if(compli in mp):
                return [mp[compli],i]
            else:
                mp[nums[i]]=i

        