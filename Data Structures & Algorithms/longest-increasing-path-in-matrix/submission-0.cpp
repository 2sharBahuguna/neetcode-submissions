class Solution {
private:
    int dfs(int n,int m,int r,int c,vector<vector<int>>& dp,vector<vector<int>>& arr)
    {
        if(dp[r][c]!=0) return dp[r][c];

        dp[r][c]=1;

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newR=r+delRow[i];
            int newC=c+delCol[i];

            if(newR>=0 && newC>=0 && newR<n && newC<m && arr[newR][newC]>arr[r][c])
            {
                dp[r][c]=max(dp[r][c],1+dfs(n,m,newR,newC,dp,arr));
            }
        }
        return dp[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        int maxi=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {     
                maxi=max(maxi,dfs(n,m,row,col,dp,matrix));
            }
        }
        return maxi;
    }
};
