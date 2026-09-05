class Solution {
private:
    void solve(int index,vector<int>& nums,vector<int>& output,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(output);
            return;
        }

        //take
        solve(index+1,nums,output,ans);
        output.push_back(nums[index]);

        solve(index+1,nums,output,ans);
        output.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(0,nums,output,ans);
        return ans;
    }
};
