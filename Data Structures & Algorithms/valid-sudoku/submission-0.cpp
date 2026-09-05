class Solution {
public:
    bool ValidRow(vector<vector<char>> board)
    {
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++)
        {
            unordered_map<char,bool> mpp;
            for(int j=0;j<col;j++)
            {
                if(board[i][j]!='.' && mpp[board[i][j]])
                {
                    return false;
                }
                mpp[board[i][j]]=true;
            }
        }
        return true;
    }

    bool ValidCol(vector<vector<char>> board)
    {
        for(int i=0;i<board[0].size();i++)
        {
            unordered_map<char,bool> visited;
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]!='.' && visited[board[j][i]])
                {
                    return false;
                }
                visited[board[j][i]]=true;
            }
        }
        return true;
    }

    bool ValidBox(vector<vector<char>> board, int startRow, int startCol) {
    unordered_map<char, bool> visited;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] != '.' && visited[board[i][j]]) {
                return false;  // Not a valid box
            }
            visited[board[i][j]] = true;
        }
    }

    return true;  // Valid box
}

    
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int startRow = 0; startRow < 9; startRow += 3) {

            for (int startCol = 0; startCol < 9; startCol += 3) {
                if (!ValidBox(board, startRow, startCol)) {
                    return false;  
                }
            }
        }

        if(ValidRow(board) && ValidCol(board) )
        {
            return true;
        }
        return false;
    }
};
