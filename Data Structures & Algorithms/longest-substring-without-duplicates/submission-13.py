class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        right=left=0
        mpp={}
        maxi=0

        while(right<len(s)):
            if s[right] in mpp:
                mpp[s[right]]+=1

            else:
                mpp[s[right]]=1

            
            while(mpp[s[right]]>1):
                mpp[s[left]]-=1
                left+=1

            maxi=max(maxi,right-left+1)
            right+=1

        return maxi

            