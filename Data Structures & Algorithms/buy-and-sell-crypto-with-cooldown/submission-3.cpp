class Solution {
private:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(idx>=prices.size()){
            return 0;
        }

        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int cost=INT_MIN;
        if(buy){ //if buy is 1, then idx u can choose to buy or skip
            cost=max(-prices[idx]+solve(idx+1,0,prices,dp),solve(idx+1,1,prices,dp));
        }
        else{ //if buy=0 , either sell or not choose to sell
            cost= max(prices[idx]+solve(idx+2,1,prices,dp),solve(idx+1,0,prices,dp));
        }

        return dp[idx][buy]=cost;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
