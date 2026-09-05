class Solution {
private:
    void dfs(int row,int col,int& area,vector<vector<int>>& arr,vector<vector<int>>& vis,int n,int m){
        vis[row][col]=1;
        area+=1;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR= row+delR[i];
            int newC= col+delC[i];

            if(newR<n && newC<m && newR>=0 && newC>=0 && !vis[newR][newC] && arr[newR][newC]==1){
                dfs(newR,newC,area,arr,vis,n,m);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int area=0;
                if(grid[row][col]==1 && !vis[row][col]){
                    dfs(row,col,area,grid,vis,n,m);
                    maxArea=max(maxArea,area); 
                }
            }
       }
       return maxArea;
    }
};
