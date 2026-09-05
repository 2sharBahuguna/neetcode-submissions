class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded_str=''
        for i in range(len(strs)):
            length_str= len(strs[i])
            encoded_str+= str(length_str)+'#'+strs[i]

        return encoded_str

    def decode(self, s: str) -> List[str]:
        ans = []
    
        i = 0
    
        while i < len(s):
            j = s.find('#', i)
    
            length = int(s[i:j])
    
            start = j + 1
    
            word = s[start:start + length]
    
            ans.append(word)
    
            i = start + length
    
        return ans


