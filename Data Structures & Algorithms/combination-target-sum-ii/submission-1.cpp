class Solution {
private:
    void solve(int index,vector<int>& arr,vector<vector<int>>& output,vector<int>& ans,int target)
    {
        if(target==0)
        {
            output.push_back(ans);
            return;
        }

        if(target<0 || index==arr.size())
        {
            return;
        }

        for(int i=index;i<arr.size();i++)
        {
            if(i!=index && arr[i]==arr[i-1]) continue;
            if(target<arr[i]) break;
            ans.push_back(arr[i]);
            solve(i+1,arr,output,ans,target-arr[i]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> output;
        vector<int> ans;
        sort(arr.begin(),arr.end());
        solve(0,arr,output,ans,target);
        return output;
    }
};
