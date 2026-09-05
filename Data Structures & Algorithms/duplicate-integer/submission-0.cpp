class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>1){
                return true;
            }
        }

        return false;
    }
};
