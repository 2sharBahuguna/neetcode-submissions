class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq={}
        for it in nums:
            freq[it]=freq.get(it,0)+1
        
        sorted_freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        ans=[]
        for key,count in sorted_freq:
            if k==0:
                return ans

            else:
                ans.append(key)

            k-=1

        return ans