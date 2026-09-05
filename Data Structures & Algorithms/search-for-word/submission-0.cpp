class Solution {
private:
    bool isValid(int index,int row,int col,int m,int n,vector<vector<char>>& board,string word)
    {
        if(index==word.size())
        {
            return true;
        }

        if(row<0 || col<0|| row>=n||col>=m||board[row][col]!=word[index]) {
            return false;
        }
        char c=board[row][col];
        board[row][col]='.';
        bool up= isValid(index+1,row,col-1,m,n,board,word);
        bool down= isValid(index+1,row,col+1,m,n,board,word);
        bool left= isValid(index+1,row-1,col,m,n,board,word);
        bool right= isValid(index+1,row+1,col,m,n,board,word);
        board[row][col]=c;
        return up||down||left||right;   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        if(n==0) return true;
        int m= board[0].size();
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                
                if(board[row][col]==word[0])
                {
                    if(isValid(0,row,col,m,n,board,word))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};