class Solution {
private:
    void solve(int index,int target,vector<vector<int>>& ans,vector<int>& output,vector<int>& nums)
    {
        if(target==0) {
            ans.push_back(output);
            return;
        }

        if(target<0 || index==nums.size())
        {
            return;
        }

        //take
        output.push_back(nums[index]);
        solve(index,target-nums[index],ans,output,nums);

        //not_take
        output.pop_back();
        solve(index+1,target,ans,output,nums);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0,target,ans,output,nums);
        return ans;
    }
};
