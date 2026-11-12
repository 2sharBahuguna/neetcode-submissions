class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sell=0
        buy=1

        maxi=0

        while(buy<len(prices)):
            if prices[sell]<prices[buy]:
                maxi=max(maxi,prices[buy]-prices[sell])

            else:
                sell=buy

            buy+=1


        return maxi