class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total=1
        is_zero=0
        for it in nums:
            if it!=0:
                total*=it
            else:
                is_zero=1;
            
        
        if not is_zero:
            for i in range(len(nums)):
                nums[i]=int(total/nums[i])

        else:
            zero_count=0
            for i in range(len(nums)):
                if(nums[i]==0):
                    nums[i]=total
                    zero_count+=1
                else:
                    nums[i]=0

            if(zero_count>1):
                return [0] * len(nums)

        return nums