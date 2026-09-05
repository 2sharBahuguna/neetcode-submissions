class Solution {
private:
    int solve(int index,vector<int>& dp,vector<int>& cost){
        if(index<0) return 0;

        if(dp[index]!=-1) return dp[index];


        return dp[index]=min(cost[index]+solve(index-1,dp,cost),cost[index]+solve(index-2,dp,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(n-1,dp,cost),solve(n-2,dp,cost));
        
    }
};
