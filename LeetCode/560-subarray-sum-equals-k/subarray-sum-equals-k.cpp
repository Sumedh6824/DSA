// class Solution {
// public:
//     // int f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
//     //     if (ind == 0) {
//     //         if (target == 0 && nums[0] == 0) return 2; // take or skip the 0
//     //         if (target == 0 || nums[0] == target) return 1;
//     //         return 0;
//     //     }
//     //     if (dp[ind][target] != -1) return dp[ind][target];

//     //     int notTake = f(ind - 1, target, nums, dp);
//     //     int take = 0;
//     //     if (nums[ind] <= target)
//     //         take = f(ind - 1, target - nums[ind], nums, dp);

//     //     return dp[ind][target] = take + notTake;
//     // }

//     // int subarraySum(vector<int>& nums, int k) {
//     //     int n = nums.size();
//     //     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     //     return f(n - 1, k, nums, dp);
//     // }

//     int subarraySum(vector<int>& nums, int k) {
//         vector<long long> dp(k + 1, 0);
//         dp[0] = 1;                          
//         for (int x : nums) {
//             for (int t = k; t >= x; t--){    
//                 dp[t] += dp[t - x];
//             }
//         }
//         return dp[k];
//     }

    
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        for (int j = 1; j <= n; j++)
            for (int i = 0; i < j; i++)
                if (pre[j] - pre[i] == k) cnt++;
        return cnt;
    }
};