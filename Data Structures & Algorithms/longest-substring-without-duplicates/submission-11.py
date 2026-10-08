class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left=0
        right=0
        maxi=0
        mapp={}
        
        while(right<len(s)):
            if s[right] in mapp:
                mapp[s[right]]+=1

            else:
                mapp[s[right]]=1

            while(mapp[s[right]]>1):
                mapp[s[left]]-=1
                left+=1



            maxi=max(maxi,right-left+1)
            right+=1

        return maxi