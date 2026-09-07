class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i=0
        j=len(heights)-1
        maxi=0
        while(i<j):
            height=min(heights[i],heights[j])
            width=j-i
            maxi=max(maxi,height*width)

            if(heights[i]<=heights[j]):
                i+=1

            elif(heights[i]>heights[j]):
                j-=1


        return maxi
