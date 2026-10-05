class Solution:
    def mul(self,nums:List[int])->int:
        ans=1
        for it in nums:
            if it==0:
                continue
            ans=ans* it

        return ans

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        count_zeroes=0
        ans=[]
        for it in nums:
            if it==0:
                count_zeroes+=1
        multi= self.mul(nums)
        if count_zeroes==0:
            for it in nums:
                val=int(multi/it)
                ans.append(val)

        elif count_zeroes==1:
            for it in nums:
                if it==0:
                    ans.append(multi)
                else:
                    ans.append(0)

        else:
            for it in nums:
                ans.append(0)


        return ans
        

        