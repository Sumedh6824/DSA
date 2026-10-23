class Solution {
public:
    int climbStairs(int n) {
        if( n <= 1) return 1;
        int l = 1;
        int r = 0;
        for(int i = 1;i<=n;i++){
            int cur = l + r;
            r = l;
            l = cur;
        }
        return l;
    }
};