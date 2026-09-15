class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map={}
        maxi=0

        start=end=0
        

        while(end<len(s)):
            map[s[end]]=map.get(s[end],0)+1

            while map[s[end]]>1:
                map[s[start]]-=1
                start+=1

            maxi=max(maxi,end-start+1)
            end+=1

        return maxi