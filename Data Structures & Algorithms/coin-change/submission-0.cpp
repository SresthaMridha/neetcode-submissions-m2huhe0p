class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp kanpsack quetsion

        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i < amount + 1; i++){
            for(auto c: coins){
                if(c <= i){
                    dp[i] = min(dp[i], dp[i-c] + 1);
                }
                
            }
        }
        if(dp[amount] == amount + 1){
            return -1;
        }
        return dp[amount];
    }
};
