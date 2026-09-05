class Solution {
private:
    void solve(int index,vector<int>& output,vector<vector<int>>& ans,vector<int>& nums,int target){
        if(target==0){
            ans.push_back(output);
            return;
        }

        if(target<0 || index==nums.size()) return ;

        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            if(target>=nums[i]){
                output.push_back(nums[i]);
                solve(i+1,output,ans,nums,target-nums[i]);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(),candidates.end());
        solve(0,output,ans,candidates,target);
        return ans;
    }
};
