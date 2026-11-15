class Solution {
public:
    int f(int ind, int T, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            return (T % coins[0] == 0);
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int notTake = f(ind - 1, T, coins, dp);
        int take = 0;
        if(coins[ind] <= T) take = f(ind, T - coins[ind], coins, dp);
        return dp[ind][T] = take + notTake;
    }
    // int change(int amount, vector<int>& coins) {
    //     // int n = coins.size();
    //     // vector<vector<int>> dp(n,vector<int>(amount + 1, -1));
    //     // return f(n-1,amount,coins,dp);

    //               //  TABULATION
    //     int n = coins.size();
    //     vector<vector<long long>> dp(n,vector<long long>(amount + 1, 0));
    //     for(int T = 0; T <= amount; T++){
    //         dp[0][T] = (T % coins[0] == 0);
    //     }

    //     for(int ind = 1; ind < n; ind++){
    //         for(int T = 0; T <=amount; T++){
    //             long long notTake = dp[ind-1][T];
    //             long long take = 0;
    //             if(coins[ind] <= T) take = dp[ind][T - coins[ind]];
    //             dp[ind][T] = take + notTake;
    //         }
    //     }
    //     return (int)dp[n-1][amount];
    // }

    int change(int amount, vector<int>& coins){
        int n = coins.size();
        // vector<vector<long long>> dp(n,vector<long long>(amount + 1, 0));
        vector<unsigned int> prev(amount+1,0) , cur(amount + 1, 0);
        for(int T = 0; T <= amount; T++){
            prev[T] = (T % coins[0] == 0);
        }

        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <=amount; T++){
                unsigned int notTake = prev[T];
                unsigned int take = 0;
                if(coins[ind] <= T) take = cur[T - coins[ind]];
                cur[T] = take + notTake;
            }
            prev = cur;
        }
        return (int)prev[amount];
    }
};