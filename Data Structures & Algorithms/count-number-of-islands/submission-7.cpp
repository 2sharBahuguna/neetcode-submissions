class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& arr,int n,int m){
        vis[row][col]=1;

        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR=row+delR[i];
            int newC= col+delC[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && arr[newR][newC]=='1'){
                dfs(newR,newC,vis,arr,n,m);
            }           
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid,row,col);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
