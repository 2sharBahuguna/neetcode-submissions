class Solution {
private:
    int solve(int prev,int index,vector<vector<int>>& dp,vector<int>& nums)
    {
        if(index==nums.size()) return 0;

        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int not_take=solve(prev,index+1,dp,nums);
        int take=0;
        if (prev == -1 || nums[index] > nums[prev])
        {
            take=1+solve(index,index+1,dp,nums);
        }

        return dp[index][prev+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(-1,0,dp,nums);
    }
};
