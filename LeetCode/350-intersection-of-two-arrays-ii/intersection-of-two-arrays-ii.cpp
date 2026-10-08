class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int temp1 = 0 , temp2 = 0;
        while(temp1 < nums1.size() && temp2 < nums2.size()){
            if(nums1[temp1] == nums2[temp2]){
                ans.push_back(nums1[temp1]);
                temp1++;
                temp2++;
            }
            else if(nums1[temp1] < nums2[temp2]){
                temp1++;
            }
            else{
                temp2++;
            }
        }
        return ans;
    }
};