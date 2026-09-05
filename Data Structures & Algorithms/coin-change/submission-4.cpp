class Solution {
private:
    int solve(int index,int target,vector<vector<int>>& dp,vector<int>& coins)
    {
        if(index==0){

            if(target%coins[0]==0) return target/coins[0];
            else return INT_MAX;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int not_take=0+solve(index-1,target,dp,coins);
        int take=INT_MAX;
        if(coins[index]<=target)
        {
            int result=solve(index,target-coins[index],dp,coins);
            if(result!=INT_MAX) take=result+1;
        }
        return dp[index][target]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,dp,coins);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
