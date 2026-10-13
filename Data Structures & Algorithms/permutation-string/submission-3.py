class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        window=len(s1)
        mpp1={}

        for i in range(len(s1)):
            if s1[i] in mpp1:
                mpp1[s1[i]]+=1
            else:
                mpp1[s1[i]]=1

        mpp2={}

        l=0
        r=0
        
        while(r<len(s2)):
            if s2[r] in mpp2:
                mpp2[s2[r]]+=1
            else:
                mpp2[s2[r]]=1

            if r-l+1>window:
                mpp2[s2[l]]-=1
                if mpp2[s2[l]] ==0:
                    del mpp2[s2[l]]
                l+=1

            if mpp1==mpp2:
                return True
            r+=1

        return False