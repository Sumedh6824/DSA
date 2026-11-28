class Solution {
public:
    // int f(int ind, int buy, int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
    //     int n = prices.size();
    //     if(ind == n || cap == 0) return 0;
    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     long profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + f(ind+1,0,cap,prices,dp) ,    // include(buy) , buy the next one
    //         0 + f(ind+1,1,cap,prices,dp));
    //     }
    //     else{
    //         profit = max(prices[ind] + f(ind+1,1,cap-1,prices,dp) ,  // sell it and buy new , keep it and look for other
    //         0 + f(ind+1,0,cap,prices,dp));
    //     }
    //     return dp[ind][buy][cap] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //     return f(0,1,2,prices,dp);
    // }

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int ind = n-1;ind >= 0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    int profit = 0;
                    if(buy == 1){
                        profit = max(-prices[ind] + dp[ind+1][0][cap],    // include(buy) , buy the next one
                        0 + dp[ind+1][1][cap]);
                    }
                    else{
                        profit = max(prices[ind] + dp[ind+1][1][cap-1] ,  // sell it and buy new , keep it and look for other
                        0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};