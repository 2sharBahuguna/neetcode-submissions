class Solution {
private:
    void solve(int index,vector<vector<int>>& ans,vector<int>& output,vector<int>& nums,int target){
        if(target==0){
            ans.push_back(output);
            return;
        }

        if(target<0 || index==nums.size()){ return;}

        if(nums[index]<=target){
            output.push_back(nums[index]);
            solve(index,ans,output,nums,target-nums[index]);
            output.pop_back();
        }
        solve(index+1,ans,output,nums,target);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0,ans,output,nums,target);
        return ans;
    }
};
