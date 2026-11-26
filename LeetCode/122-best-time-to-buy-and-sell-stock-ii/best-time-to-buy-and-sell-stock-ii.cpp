class Solution {
public:
    int f(int ind, int buy, vector<int>& prices,vector<vector<int>>& dp, int n){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,prices,dp,n) ,    // include(buy) , buy the next one
            0 + f(ind+1,1,prices,dp,n));
        }
        else{
            profit = max(prices[ind] + f(ind+1,1,prices,dp,n) ,  // sell it and buy new , keep it and look for other
            0 + f(ind+1,0,prices,dp,n));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,n);
    }
};