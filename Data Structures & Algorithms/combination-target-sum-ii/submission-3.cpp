class Solution {
private:
    void solve(int index,vector<int>& ans,vector<vector<int>>& output,vector<int>& arr,int target){
        if(target==0){
            output.push_back(ans);
            return;
        }   

        if(target<0 || index==arr.size()) return;

        for(int i=index;i<arr.size();i++){
            if(i!=index && arr[i]==arr[i-1]) continue;
            if(arr[index]<=target){
                ans.push_back(arr[i]);
                solve(i+1,ans,output,arr,target-arr[i]);

                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> ans;
        vector<vector<int>> output;
        sort(arr.begin(),arr.end());
        solve(0,ans,output,arr,target);
        return output;
    }
};
