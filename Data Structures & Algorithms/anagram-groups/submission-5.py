class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans=[]
        freq={}
        for i in range(len(strs)):
            dupli= strs[i]
            sorted_dupli=''.join(sorted(dupli))

            if sorted_dupli in freq:
                freq[sorted_dupli].append(strs[i])
            else:
                freq[sorted_dupli]=[strs[i]]

        for k,v in freq.items():
            ans.append(v)

        return ans

        


        