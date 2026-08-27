class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] >= target) {
        //         return i;
        //     }
        // }
        // return nums.size(); 

        int n = nums.size();
        int left = 0 , right = n - 1;
        int ans = n;
        while( left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] >= target){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};