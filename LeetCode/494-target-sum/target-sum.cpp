class Solution {
public:
    int f(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> prev(target+1,0) , cur(target+1,0);
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0] != 0 && nums[0] <= target) prev[nums[0]] = 1;
        for(int ind = 1; ind<n;ind++){
            for(int sum = 0;sum <= target;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(nums[ind] <= sum) take = prev[sum - nums[ind]];

                cur[sum] = take + notTake;
            }
            prev = cur;
        }
        return prev[target];
    }

    int countPartitions(int n, int d, vector<int>& arr){
        int totSum = 0;
        for(auto &it : arr) totSum += it;
        if(totSum - d < 0 || (totSum - d) % 2) return false;
        return f(arr, (totSum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};