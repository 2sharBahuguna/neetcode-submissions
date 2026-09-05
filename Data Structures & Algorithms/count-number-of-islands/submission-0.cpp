class Solution {
private:
    void bfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r =q.front().first;
            int c =q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow= r+delrow[i];
                int ncol= c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }    
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]=='1' && !visited[row][col])
                {
                    count++;
                    bfs(row,col,n,m,grid,visited);
                }
            }
        }
        return count;
    }
};
