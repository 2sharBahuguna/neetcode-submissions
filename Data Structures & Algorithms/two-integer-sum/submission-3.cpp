class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int compli= target-nums[i];

            if(mp.find(compli)!=mp.end()){
                return {mp[compli],i};
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};
