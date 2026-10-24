class Solution {
public:
    unordered_map<int,int> pos;      // stone position -> index
    vector<vector<int>> dp;

    bool f(vector<int>& stones, int ind, int k) {
        int n = stones.size();
        if (ind == n - 1) return true;
        if (dp[ind][k] != -1) return dp[ind][k];

        for (int step = k - 1; step <= k + 1; step++) {
            if (step <= 0) continue;
            int next = stones[ind] + step;
            if (pos.count(next)) {
                if (f(stones, pos[next], step)) return dp[ind][k] = true;
            }
        }
        return dp[ind][k] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;   // first jump must be exactly 1
        for (int i = 0; i < n; i++) pos[stones[i]] = i;
        dp.assign(n, vector<int>(n + 1, -1));
        return f(stones, 1, 1);             // standing on stone 1 after a jump of 1
    }
};