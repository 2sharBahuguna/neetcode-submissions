class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;

        int sell=0;
        int buy=1;

        while(buy<prices.size())
        {
            if(prices[sell]<prices[buy])
            {
                max_profit=max(max_profit,prices[buy]-prices[sell]);
                
            }
            else
            {
                sell=buy;
            }
            buy++;
        }

        return max_profit;


    }
};
