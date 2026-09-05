class Solution {
private:
    bool solve(int idx,int target,vector<int>& arr, vector<vector<int>>& dp){
        if(target==0) return true;
        if(idx<0) return false;

        if(dp[idx][target]!=-1) return dp[idx][target];

        bool not_take=solve(idx-1,target,arr,dp);
        bool take= false;

        if(arr[idx]<=target){
            take= solve(idx-1,target-arr[idx],arr,dp);
        }

        return dp[idx][target]= take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum&1) return false;
        int target= sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};
