class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count=0;

        vector<int> ans(nums.size(),0);
        int sum=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero_count++;
            else{
                sum*=nums[i];
            }
        }

        if(zero_count>1) return ans;

        else{
            if(zero_count>0){
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==0){
                        ans[i]=sum;
                    }
                    else{
                        ans[i]=0;
                    }
                }
            }
            else{
                for(int i=0;i<nums.size();i++){
                    ans[i]=sum/nums[i];
                }
            }
        }
        return ans;

    }
};
