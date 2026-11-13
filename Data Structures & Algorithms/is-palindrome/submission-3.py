class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_s=""
        for ch in s:
            if ch.isalnum():
                new_s+=ch.lower()
        
        rev_s=new_s[::-1]

        return rev_s==new_s

        