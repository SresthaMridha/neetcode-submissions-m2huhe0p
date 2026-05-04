class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = INT_MAX;
        int maxprofit = 0;
        for(auto x: prices){
            minbuy = min(minbuy,x);
            int profit = x - minbuy;
            maxprofit = max(profit,maxprofit);
        }
        return maxprofit;
    }
};
