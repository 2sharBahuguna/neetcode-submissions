class Solution {
private:
    int solve(int idx,vector<int>& cost,vector<int>& dp){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one_step = cost[idx]+ solve(idx-1,cost,dp);
        int two_step = cost[idx]+ solve(idx-2,cost,dp);
        return dp[idx]=min(one_step,two_step);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
        
    }
};
