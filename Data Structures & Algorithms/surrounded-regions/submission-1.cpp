class Solution {
private:
    void convert(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis)
    {
        int n=board.size();
        int m=board[0].size();
        if(row<0 || col<0 || row>=n || col>=m || vis[row][col] || board[row][col]!='O')
        {
            return;
        }

        vis[row][col]=1;
        board[row][col]='T';

        convert(row-1,col,board,vis);
        convert(row+1,col,board,vis);
        convert(row,col-1,board,vis);
        convert(row,col+1,board,vis);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
                {
                    convert(i,j,board,vis);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};
