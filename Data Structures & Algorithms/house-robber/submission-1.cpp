class Solution {
private:
    int solve(int index,vector<int>& nums,vector<int>& dp)
    {
        if(index<0)
        {
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        
        int take = nums[index] + (index >= 2 ? solve(index - 2, nums, dp) : 0);
        int not_take=solve(index-1,nums,dp);
        return dp[index]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};
