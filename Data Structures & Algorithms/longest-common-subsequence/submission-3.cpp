class Solution {
private:
    int solve(int i,int j,string& text1,string&text2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int not_found=max(solve(i,j-1,text1,text2,dp),solve(i-1,j,text1,text2,dp));
        int found=0;
        if(text1[i]==text2[j]){
            found=1+solve(i-1,j-1,text1,text2,dp);
        }
        return dp[i][j]=max(found,not_found);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m= text2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(n-1,m-1,text1,text2,dp);
    }
};
