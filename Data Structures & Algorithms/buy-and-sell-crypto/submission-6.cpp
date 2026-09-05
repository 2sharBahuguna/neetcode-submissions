class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=0;
        int maxi=0;

        while(r<prices.size()){
            if(prices[l]< prices[r]){
                maxi=max(maxi,prices[r]-prices[l]);
            }
            else{
                l=r;
            }
            r++;
        }

        return maxi;
    }
};
