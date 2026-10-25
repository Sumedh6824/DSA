class Solution {
public:

          // RECURSION METHOD
    // int f(int ind,vector<int> &nums){
    //     if(ind == 0) return nums[ind];
    //     if(ind < 0) return 0;
    //     int pick = nums[ind] + f(ind - 2,nums);
    //     int not_pick = f(ind - 1,nums) + 0;
    //     return max(pick,not_pick);
    // }
    // int rob(vector<int>& nums) {
    //     int ind = nums.size() - 1;
    //     return f(ind,nums);
    // }

          // memoization
    // int f(int ind,vector<int> &nums, vector<int>& dp){
    //     if(ind == 0) return nums[ind];
    //     if(ind < 0) return 0;
    //     if(dp[ind] != -1) return dp[ind];
    //     int pick = nums[ind] + f(ind - 2,nums,dp);
    //     int not_pick = f(ind - 1,nums,dp) + 0;
    //     return max(pick,not_pick);
    // }
    // int rob(vector<int>& nums){
    //     int ind = nums.size() - 1;
    //     vector<int> dp(nums.size(), -1);
    //     return f(ind,nums,dp);
    // }

         // tabulation
    // int rob(vector<int>& nums){
    //     int n = nums.size();
    //     if(n == 0) return 0;
    //     vector<int> dp(nums.size() , -1);
    //     dp[0] = nums[0];
    //     for(int i = 1;i<nums.size();i++){
    //         int take = nums[i];
    //         if(i > 1) take += dp[i-2];
    //         int not_take = dp[i-1];
    //         dp[i] = max(take,not_take);
    //     }
    //     return dp[n-1];
    // }

         // SPACE OPTIMIZATION
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1;i<n;i++){
            int take = nums[i];
            if(i> 1) take += prev2;
            int notTake = prev + 0;
            int cur = max(take,notTake);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};