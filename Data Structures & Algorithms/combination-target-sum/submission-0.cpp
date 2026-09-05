class Solution {
vector<vector<int>> ans;
private:
    void solve(vector<int>& output,int index,vector<int> candidates,int target)
    {
        if(target==0)
        {
            ans.push_back(output);
            return;
        }
        if(index==candidates.size()||target<0)
        {
            return;
        }

        //pick
        output.push_back(candidates[index]);
        solve(output,index,candidates,target-candidates[index]);

        //not pick
        output.pop_back();
        solve(output,index+1,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> output;
        int index=0;
        solve(output,index,candidates,target);
        return ans;
    }
};