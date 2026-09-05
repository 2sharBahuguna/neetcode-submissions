class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        priority_queue<int> pq;

        for(auto it: nums){
            pq.push(it);
        }
        int ans=0;
        while(k--){
            ans=pq.top();
            pq.pop();
        }

        return ans;
        
    }
};
