class Solution:
    def isValidCol(self,board:List[List[str]],row:int)->bool:
        flag={}
        
        for col in range(9):
            if board[row][col]=='.':
                continue
            if  board[row][col] in flag:
                return False
            else:
                flag[board[row][col]]=True

        return True

    def isValidRow(self,board:List[List[str]],col:int)->bool:
        flag={}
        
        for row in range(9):
            if board[row][col]=='.':
                continue
            if board[row][col] in flag:
                return False
            else:
                flag[board[row][col]]=True

        return True

    def isValidBox(self,board:List[List[str]],row:int,col:int)->bool:
        isVisited={}
        for i in range(row,row+3):
            for j in range(col,col+3):
                if board[i][j]=='.':
                    continue
                if board[i][j] in isVisited:
                    return False
                else:
                    isVisited[board[i][j]]=True

        return True


    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows=len(board)
        cols=len(board[0])
        
        for row in range(rows):
            if not self.isValidCol(board,row):
                return False

        for col in range(cols):
            if not self.isValidRow(board,col):
                return False

        for i in range(0,9,3):
            for j in range(0,9,3):
                if not self.isValidBox(board,i,j):
                    return False


        return True