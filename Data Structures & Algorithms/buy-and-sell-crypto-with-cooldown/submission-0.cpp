class Solution {
private:
    int solve(int index,int buy,vector<vector<int>>& dp,vector<int>& prices)
    {
        if(index>=prices.size())
        {
            return 0;
        }

        if(dp[index][buy]!=-1) return dp[index][buy];
        int cost=INT_MIN;
        if(buy)
        {
            cost=max(-prices[index]+solve(index+1,0,dp,prices),solve(index+1,1,dp,prices));
        }
        else
        {
            cost=max(prices[index]+solve(index+2,1,dp,prices),solve(index+1,0,dp,prices));
        }

        return dp[index][buy]=cost;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return solve(0,1,dp,prices);
    }
};
