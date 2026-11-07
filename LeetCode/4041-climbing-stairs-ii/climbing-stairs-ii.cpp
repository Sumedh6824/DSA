class Solution {
public:
    // int climbStairs(int n, vector<int>& costs) {
    //     const int INF = INT_MAX;
    //     vector<int> dp(n + 1, INF);
    //     dp[0] = 0;

    //     for (int j = 1; j <= n; j++) {
    //         for (int k = 1; k <= 3; k++) {
    //             int i = j - k;
    //             if (i >= 0 && dp[i] != INF) {
    //                 dp[j] = min(dp[j], dp[i] + costs[j - 1] + k * k);
    //             }
    //         }
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n, vector<int>& costs) {
        // a = dp[j-3], b = dp[j-2], c = dp[j-1]
        long long a = LLONG_MAX / 2, b = LLONG_MAX / 2, c = 0;

        for (int j = 1; j <= n; j++) {
            long long cur = min({c + 1, b + 4, a + 9}) + costs[j - 1];
            a = b;
            b = c;
            c = cur;
        }
        return (int)c;
    }
};