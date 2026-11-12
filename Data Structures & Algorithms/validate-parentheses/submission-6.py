class Solution:
    def isValid(self, s: str) -> bool:
        st=[]

        for ch in s:
            if ch in "[{(":
                st.append(ch)

            elif st and ((ch =="]" and st[-1]=="[") or
                (ch =="}" and st[-1] == "{") or
                (ch == ")" and st[-1]=="(")):
                st.pop()

            else:
                return False

        
        return len(st)==0
            
        