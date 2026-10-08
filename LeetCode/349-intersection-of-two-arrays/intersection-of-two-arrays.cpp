class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> st;
        int temp1 = 0 , temp2 = 0;
        while(temp1 < nums1.size() && temp2 < nums2.size()){
            if(nums1[temp1] == nums2[temp2]){
                st.insert(nums1[temp1]);
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
        return vector<int>(st.begin(), st.end());
    }
};