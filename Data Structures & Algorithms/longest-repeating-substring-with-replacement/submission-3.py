class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mpp={}
        maxi=result=l=r=0


        while(r<len(s)):
            if s[r] in mpp:
                mpp[s[r]]+=1
            else:
                mpp[s[r]]=1

            maxi=max(maxi,mpp[s[r]])

            while((r-l+1)-maxi>k):
                mpp[s[l]]-=1
                l+=1

            result=max(result,r-l+1)
            r+=1

        return result

