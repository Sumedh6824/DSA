class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int p1 = 0;
        int p2 = 1;
        for(int i = 0 ;i<nums.size();i++){
            if(p2 >= nums.size())return nums[p1];
            if(nums[p1] != nums[p2]){
                return nums[p1];
            }
            p1 = p2 + 1;
            p2 = p1 + 1;
        }
        return -1;
    }
};