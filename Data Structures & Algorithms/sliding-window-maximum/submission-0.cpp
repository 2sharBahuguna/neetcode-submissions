class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=k-1;
        vector<int> ans;
        while(r<nums.size())
        {
            int maxi=INT_MIN;

            for(int i=l;i<=r;i++)
            {
                maxi=max(maxi,nums[i]);
            }
            ans.push_back(maxi);
            l++;
            r++;
        }

        return ans;

    }
};
