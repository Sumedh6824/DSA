class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid == nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};