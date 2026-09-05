class Solution {
private:
    void dfs(int row,int col,int n,int m,vector<vector<int>>& vis,vector<vector<int>>& grid,int & area){
        vis[row][col]=1;
        area++;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR= row+delR[i];
            int newC= col+delC[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC]==1){
                
                dfs(newR,newC,n,m,vis,grid,area);
            } 
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxArea=0;;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int area=0;
                if(grid[row][col]==1 && !vis[row][col]){
                    dfs(row,col,n,m,vis,grid,area);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
