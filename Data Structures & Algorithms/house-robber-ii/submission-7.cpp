class Solution {
private:
    int solve(vector<int>& nums)
    {
        int prev=0;
        int prev2=0;
        int curri=0;
        for(int i=0;i<nums.size();i++)
        {
            curri=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curri;
        }

        return curri;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];

        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);

        return max(solve(numsA),solve(numsB));
    }
};
