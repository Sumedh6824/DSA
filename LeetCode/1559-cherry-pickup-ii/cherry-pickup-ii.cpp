class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> next(C, vector<int>(C, 0)), cur(C, vector<int>(C, 0));

        for (int r = R - 1; r >= 0; r--) {
            for (int c1 = 0; c1 < C; c1++) {
                for (int c2 = 0; c2 < C; c2++) {
                    int best = 0;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int n1 = c1 + d1, n2 = c2 + d2;
                            if (n1 >= 0 && n1 < C && n2 >= 0 && n2 < C)
                                best = max(best, next[n1][n2]);
                        }
                    }
                    int gain = grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
                    cur[c1][c2] = gain + best;
                }
            }
            swap(cur, next);
        }
        return next[0][C - 1];
    }
};