class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        

        if(row>=0 && col>=0 && row<n && col<m && board[row][col]=='O'){

            board[row][col]='T';

            dfs(row+1,col,board);
            dfs(row-1,col,board);
            dfs(row,col+1,board);
            dfs(row,col-1,board);
        }
        else{
            return ;
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        //all border elements that are O mark them as T
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col]=='O' && (row==0 || col ==0 || row==n-1 || col==m-1)){
                    dfs(row,col,board);
                }   
            }
        }

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col]=='O'){
                    board[row][col]='X';
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};
