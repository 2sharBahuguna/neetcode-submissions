class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n=len(matrix)
        m= len(matrix[0])

        start=0
        end=(n*m)-1

        while(start<=end):
            mid=(start+end) // 2
            row= mid // m
            col=mid%m

            if matrix[row][col] == target:
                return True

            elif matrix[row][col]<target:
                start=mid+1

            else:
                end = mid-1

        return False
        