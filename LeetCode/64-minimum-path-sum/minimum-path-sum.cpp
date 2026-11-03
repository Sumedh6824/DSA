class Solution {
public:
    //                 MEMOISATION
    // int f(vector<vector<int>>& grid, vector<vector<int>>& dp, int m , int n){
    //     if(m == 0 && n == 0) return grid[0][0];
    //     if(m< 0 || n < 0) return INT_MAX;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     int up = f(grid,dp,m-1,n);
    //     int left = f(grid,dp,m,n-1);
    //     return dp[m][n] = grid[m][n] + min(left,up);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return f(grid,dp,m-1,n-1);
    // }

    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int up = (i > 0) ? dp[i-1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j-1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};