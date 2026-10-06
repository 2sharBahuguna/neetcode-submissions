class Solution:
    def isValid(self, s: str) -> bool:
        st=[]

        for i in range(len(s)):
            if s[i] in "({[":
                st.append(s[i])
            
            elif st and ((s[i]=='}' and st[-1]=='{') or (s[i]==']' and st[-1]=='[') or (s[i]==')' and st[-1]=='(')):
                st.pop()

            else:
                return False

        return not st