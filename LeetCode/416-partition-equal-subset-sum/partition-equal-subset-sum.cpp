class Solution {
public:
    bool SubsetSumToK(int n,int k, vector<int> &nums){
        vector<bool> prev(k+1,0) , cur(k+1,0);
        prev[0] = cur[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;
        for(int ind = 1;ind < n;ind++){
            for(int target = 1;target <= k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target) take = prev[target - nums[ind]];
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<nums.size();i++){
            totSum += nums[i];
        }
        if(totSum % 2) return false;
        int target = totSum / 2;
        return SubsetSumToK(n,target,nums);
    }
};