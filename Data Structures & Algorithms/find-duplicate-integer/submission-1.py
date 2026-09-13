class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        mapp={}

        for it in nums:
            mapp[it]=mapp.get(it,0)+1

        for ele,cnt in mapp.items():
            if cnt>1:
                return ele
        
        return 0