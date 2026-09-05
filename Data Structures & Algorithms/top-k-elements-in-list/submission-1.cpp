class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
