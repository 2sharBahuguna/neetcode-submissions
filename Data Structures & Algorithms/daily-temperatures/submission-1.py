class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)

        stack=[]
        ans=[0]*n

        for i in range(n):
            curr=temperatures[i]

            while stack and curr>temperatures[stack[-1]]:
                past_day=stack.pop()
                ans[past_day]=i-past_day

            stack.append(i)

        return ans