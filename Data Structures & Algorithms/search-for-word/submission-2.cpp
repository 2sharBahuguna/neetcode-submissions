class Solution {
private:
    bool solve(int index,int row,int col,int n,int m,vector<vector<char>>& board,string& word,vector<vector<int>>& visited){
        
        if(index==word.size()) return true;
        
        if(row<0 || col<0 || row>=n || col>=m || visited[row][col] ||board[row][col]!=word[index]) return false;
        visited[row][col]=1;


        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR=row+delrow[i];
            int newC=col+delcol[i];

            if(solve(index+1,newR,newC,n,m,board,word,visited)){
                return true;
            }
        }
        visited[row][col]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
        int m =board[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col]==word[0]){
                    if(solve(0,row,col,n,m,board,word,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
