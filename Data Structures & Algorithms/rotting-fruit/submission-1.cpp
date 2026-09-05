class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int fresh_count=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(grid[row][col]==2)
                {
                    q.push({{row,col},0});
                    visited[row][col]=1;
                }
                else if(grid[row][col]==1)
                {
                    fresh_count++;
                }
            }
        }
        int time=0;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int curr_time=q.front().second;

            time=max(time,curr_time);

            for(int i=0;i<4;i++)
            {
                int newR=r+delR[i];
                int newC=c+delC[i];

                if(newR>=0 && newC>=0 && newC<m && newR<n && grid[newR][newC]==1 && !visited[newR][newC])
                {
                    fresh_count--;
                    visited[newR][newC]=1;
                    q.push({{newR,newC},time+1});
                }
            }
            q.pop();
        }

        if(fresh_count!=0) return -1;
        return time;
    }
};
