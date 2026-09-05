class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq={}

        for it in s:
            freq[it]= freq.get(it,0)+1        
        for it in t:
            if it in freq:
                freq[it]= freq.get(it,0)-1
            else:
                return False

        return all(count==0 for count in freq.values())
         