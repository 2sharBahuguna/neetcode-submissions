class Solution {
private:
    void dfs(int r,int c,int n,int m,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[r][c]=1;
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR=r+row[i];
            int newC=c+col[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]=='1' && !vis[newR][newC]){
                dfs(newR,newC,n,m,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    dfs(row,col,n,m,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
