class Solution {
private:
    void dfs(int row,int col, vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m,int& count){
        vis[row][col]=1;
        count++;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR= row+delR[i];
            int newC= col+delC[i];

            if(newR<n && newC<m && newR>=0 && newC>=0 && grid[newR][newC]==1 && !vis[newR][newC]){
                dfs(newR,newC,grid,vis,n,m,count);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int count=0;
                if(grid[row][col]==1 && !vis[row][col]){
                    dfs(row,col,grid,vis,n,m,count);
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};
