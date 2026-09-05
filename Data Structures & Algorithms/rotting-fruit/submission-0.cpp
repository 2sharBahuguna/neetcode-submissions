class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh_count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1)
                {
                    fresh_count++;                    
                }
            }
        }
        int time=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r =q.front().first.first;
            int c =q.front().first.second;
            int currtime=q.front().second;
            time=max(time,currtime);
            for(int i=0;i<4;i++)
            {
                int newR= r+ delrow[i];
                int newC= c+delcol[i];
                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]==1 && !vis[newR][newC])
                {
                    fresh_count--;
                    vis[newR][newC]=1;
                    q.push({{newR,newC},currtime+1});
                }
            }
            q.pop();
        }
        if(fresh_count!=0) return -1;
        return time;
    }
};
