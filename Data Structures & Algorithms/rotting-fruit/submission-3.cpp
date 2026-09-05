class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int fresh_count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    q.push({{row,col},0});
                    vis[row][col]=1;
                }
                else if(grid[row][col]==1){
                    fresh_count++;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int curr_time=q.front().second;
            q.pop();
            
            time=max(time,curr_time);

            int delR[]={-1,0,1,0};
            int delC[]={0,1,0,-1};            

            for(int i=0;i<4;i++){
                int newR=r+delR[i];
                int newC=c+delC[i];

                if(newR<n && newC<m && newR>=0 && newC>=0 && grid[newR][newC]==1 && !vis[newR][newC]){
                    q.push({{newR,newC},time+1});
                    fresh_count--;
                    vis[newR][newC]=1;
                }
            }
        }   

        if(fresh_count!=0) return -1;
        return time;
    }
};
