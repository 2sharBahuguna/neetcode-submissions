class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i=0;
        j= len(numbers)-1
        ans=[]
        while(i<=j):
            sum= numbers[i]+numbers[j]
            if(sum==target):
                ans.extend([i + 1, j + 1])
                break
                
            if(sum>target):
                j-=1

            else:
                i+=1

        return ans
            
                
        