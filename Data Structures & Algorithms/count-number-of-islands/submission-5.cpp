class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m){
        vis[row][col]=1;

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR=row+delRow[i];
            int newC=col+delCol[i];

            if(newR>=0 && newC>=0 && newC<m && newR<n && grid[newR][newC]=='1' && !vis[newR][newC]){
                dfs(newR,newC,grid,vis,n,m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    dfs(row,col,grid,vis,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};
