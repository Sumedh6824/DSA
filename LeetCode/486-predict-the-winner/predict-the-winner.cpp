// class Solution {
// public:
//     int f(vector<int>& nums,vector<int>& p1,vector<int>& p2,int t1, int t2,int cnt){
//         if(nums.size() == 0) return max(t1,t2);
//         int left = 0;
//         int right = nums.size() - 1;
//         if(cnt % 2 == 0){
//             if(nums[left] >= nums[right]){
//                 p1.push_back(nums[left]);
//                 t1 += nums[left];
//                 nums.erase(nums.begin());
//             }
//             else{
//                 p1.push_back(nums[right]);
//                 t1 += nums[right];
//                 nums.pop_back();
//             }
//         }
//         else{
//             if(nums[left] >= nums[right]){
//                 p2.push_back(nums[left]);
//                 t2 += nums[left];
//                 nums.erase(nums.begin());
//             }
//             else{
//                 p2.push_back(nums[right]);
//                 t2 += nums[right];
//                 nums.pop_back();
//             }
//         }
//         cnt++;
//         return f(nums,p1,p2,t1,t2,cnt);
//     }
//     bool predictTheWinner(vector<int>& nums) {
//         vector<int> p1 , p2;
//         int t1 = 0 , t2 = 0;
//         int cnt = 0;
//         if(f(nums,p1,p2,t1,t2,cnt) == t1) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool f(vector<int>& nums, int l, int r, int t1, int t2, bool p1Turn) {
        if (l > r) return t1 >= t2;  

        if (p1Turn) {
            return f(nums, l + 1, r, t1 + nums[l], t2, false) ||
                   f(nums, l, r - 1, t1 + nums[r], t2, false);
        }
        return f(nums, l + 1, r, t1, t2 + nums[l], true) &&
               f(nums, l, r - 1, t1, t2 + nums[r], true);
    }

    bool predictTheWinner(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1, 0, 0, true);
    }
};