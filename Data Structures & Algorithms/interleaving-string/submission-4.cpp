class Solution {
private:
    int solve(int i,int j, vector<vector<int>>& dp,string& s1,string& s2)
    {
        if(j<0) return 0;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j])
        {
            dp[i][j]=1+solve(i-1,j-1,dp,s1,s2);
        }
        else
        {
            dp[i][j]=solve(i-1,j,dp,s1,s2);
        }

        return dp[i][j];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int z=s3.size();
        if(n+m!=z) return false;
        if(n==0 && m==0 && z==0) return true;

        vector<vector<int>> dp1(z,vector<int>(n,-1));
        vector<vector<int>> dp2(z,vector<int>(m,-1));

        int ans1=solve(z-1,n-1,dp1,s3,s1);
        int ans2=solve(z-1,m-1,dp2,s3,s2);

        if(ans1+ans2==s3.size()) return true;

        return false; 
    }
};
