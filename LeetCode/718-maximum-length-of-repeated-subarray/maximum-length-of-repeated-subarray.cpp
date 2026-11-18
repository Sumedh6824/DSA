class Solution {
public:
    //                    TABULATION
    // int findLength(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    //     for(int j = 0; j<=m;j++) dp[0][j] = 0;
    //     for(int i = 0; i<=n; i++) dp[i][0] = 0;
    //     int ans = 0;
    //     for(int i = 1;i<=n;i++){
    //         for(int j = 1;j<=m;j++){
    //             if(nums1[i-1] == nums2[j-1]) {
    //                 dp[i][j] = 1 + dp[i-1][j-1];
    //                 ans = max(ans,dp[i][j]);
    //             }
    //             else dp[i][j] = 0;
    //         }
    //     }
    //     return ans;
    // }

    //              SPACE OPTIMIZATION
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,0), cur(m+1,0);
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]) {
                    cur[j] = 1 + prev[j-1];
                    ans = max(ans,cur[j]);
                }
                else cur[j] = 0;
            }
            prev = cur;
        }
        return ans;
    }
};