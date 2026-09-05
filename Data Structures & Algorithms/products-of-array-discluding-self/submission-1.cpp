class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int zero_count=0;
        int totalProduct=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                totalProduct*=nums[i];
            }
            else{
                zero_count++;
            }
        }

        if(zero_count>1){
            return res;
        }

        for(int i=0;i<nums.size();i++){
            if(zero_count>0){
                if(nums[i]==0){
                    res[i]=totalProduct;
                }
                else{
                    res[i]=0;
                }
            }
            else{
                res[i]=totalProduct/nums[i];
            }
        }
        

        return res;
    }
};
