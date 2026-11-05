class Solution {
public:
     //             MEMOISATION
    // int f(vector<vector<int>>& matrix, int i ,int j,vector<vector<int>>& dp){
    //     int n = matrix.size();
    //     if(j < 0 || j > n-1) return 1e9;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == 0) return dp[i][j] = matrix[i][j];
    //     int ld = matrix[i][j] + f(matrix,i-1,j-1,dp);
    //     int up = matrix[i][j] + f(matrix,i-1,j,dp);
    //     int rd = matrix[i][j] + f(matrix,i-1,j+1,dp);
    //     return dp[i][j] = min(up,min(ld,rd));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     int minp = INT_MAX;
    //     for(int j = 0;j<n;j++){
    //         minp =  min(minp,f(matrix,n-1,j,dp));
    //     }
    //     return minp;
    // }
    
    //          TABULATION
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j = 0;j<n;j++) dp[0][j] = matrix[0][j];
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j-1 >= 0) ld += dp[i-1][j-1];
                else ld += 1e9;
                int rd = matrix[i][j];
                if(j+1 < n) rd += dp[i-1][j+1];
                else rd += 1e9;
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        int minp = INT_MAX;
        for(int j = 0;j<n;j++){
            minp = min(minp,dp[n-1][j]);
        }
        return minp;
    }
};