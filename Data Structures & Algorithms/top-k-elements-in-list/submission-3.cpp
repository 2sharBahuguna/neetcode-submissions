class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()<k) return {};
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;

        for(auto it:nums){
            mp[it]++;
        }

        for(auto mapping:mp){
            pq.push({mapping.second,mapping.first});
        }

        vector<int> ans;
        while(!pq.empty() && k--){
            int value=pq.top().second;
            pq.pop();
            ans.push_back(value);
        }

        return ans;

    }
};
