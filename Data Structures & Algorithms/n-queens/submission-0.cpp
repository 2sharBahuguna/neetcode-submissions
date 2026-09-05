class Solution {
private:
    bool isSafe(int col,int row,vector<string>& board,int n)
    {
        
        int Duprow=row;
        int Dupcol=col;

        //upper diagnol
        while(Duprow>=0 && Dupcol>=0)
        {
            if(board[Duprow][Dupcol]=='Q')
            {
                return false;
            }
            Duprow--;
            Dupcol--;
        }

        Duprow=row;
        Dupcol=col;

        //left
        while(Dupcol>=0)
        {
            if(board[Duprow][Dupcol]=='Q')
            {
                return false;
            }
            Dupcol--;
        }

        Duprow=row;
        Dupcol=col;
        //bottom diagnol
        while(Duprow<n && Dupcol>=0)
        {
            if(board[Duprow][Dupcol]=='Q')
            {
                return false;
            }
            Dupcol--;
            Duprow++;
        }

        return true;
    }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(col,row,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,board,ans,n);
        return ans;
    }
};
