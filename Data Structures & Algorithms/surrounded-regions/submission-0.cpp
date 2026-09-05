class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row==0)
        {
            return;
        }
        int col = board[0].size();
        

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] =='O' && (i==0 ||j==0 || i==row-1 ||j==col-1))
                {
                    dfs(board,i,j);
                }
            }
        }


        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }        
        

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board,int r,int c)
    {
        int ROWS = board.size();
        int COLS = board[0].size();

        if (r < 0 || c < 0 || r == ROWS || c == COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};

