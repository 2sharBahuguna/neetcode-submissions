class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st=[]
        
        for ch in tokens:

            if ch in "+-/*":
                b=st.pop()
                a=st.pop()

                if ch=="+":
                    st.append(b+a)
                elif ch=="-":
                    st.append(a-b)
                elif ch=="/":
                    st.append(int(a/b))
                else:
                    st.append(a*b)
            else:
                st.append(int(ch))

        return st[-1]


            


        