class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int maxprofit = 0;
        int profit;
        for(int i = 0; i < prices.size();i++){
            minBuy = min(prices[i],minBuy);
            //if sell.
            if(prices[i]>minBuy){
                profit = prices[i]-minBuy;
                maxprofit = max(maxprofit, profit);
            }
            
        }
        return maxprofit;
    }
};
