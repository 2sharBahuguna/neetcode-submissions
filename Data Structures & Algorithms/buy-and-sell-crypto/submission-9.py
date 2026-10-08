class Solution:
    def maxProfit(self, prices: List[int]) -> int:
            buy=0
            sell=1
            maxi=0
            while(sell<len(prices)):
                profit=prices[sell]-prices[buy]

                if(prices[sell]>prices[buy]):
                    maxi=max(maxi,profit)

                else:
                    buy=sell

                sell+=1

            return maxi