class Solution {
private:
    int solve(int idx,vector<int>& cost,vector<int>& dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=min((cost[idx]+solve(idx-1,cost,dp)),cost[idx]+solve(idx-2,cost,dp));
        
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        
    }
};
