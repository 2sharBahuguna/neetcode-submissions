class Solution {
private:
    int solve(int index,int target,vector<vector<int>>& dp,vector<int>& arr)
    {
        if(index==0)
        {
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int not_take=solve(index-1,target,dp,arr);

        int take=0;
        if(arr[index]<=target)
        {
            take=solve(index-1,target-arr[index],dp,arr);
        }

        return dp[index][target]=take+not_take;
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum+=nums[i];
        }

        if(total_sum-target<0) return 0;

        if((total_sum-target)%2==1)
        {
            return 0;
        }

        int s2=(total_sum-target)/2;

        vector<vector<int>> dp(n,vector<int>(s2+1,-1));

        return solve(n-1,s2,dp,nums);
    }
};
