class Solution:
    def isPalindrome(self, s: str) -> bool:
        letters=''
        s=s.lower()

        for it in s:
            if it.isalnum():
                letters+=it

        rev=letters[::-1]

        return rev==letters