class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mpp={}

        for i in range(len(numbers)):
            compliment=target-numbers[i]

            if compliment in mpp:
                return [mpp[compliment],i]

            else:
                mpp[numbers[i]]=i


        return []