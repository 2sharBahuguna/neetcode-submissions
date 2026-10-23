class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1={}

        for char in s1:
            if char not in mp1:
                mp1[char]=1
            else:
                mp1[char]+=1

        mp2={}
        window=len(s1)
        l=r=0

        while(r<len(s2)):
            if s2[r] not in mp2:
                mp2[s2[r]]=1
            else:
                mp2[s2[r]]+=1

            if r-l+1>window:
                mp2[s2[l]]-=1

                if mp2[s2[l]]==0:
                    del mp2[s2[l]]
                l+=1

            if mp1==mp2:
                return True

            r+=1

        return False

