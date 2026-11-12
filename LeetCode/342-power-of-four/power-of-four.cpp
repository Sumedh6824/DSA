class Solution {
public:
    bool f(int n){
        if(n == 1) return true;
        if(n % 4 != 0) return false;
        int next = n / 4;
        return f(next);
    }
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return f(n);
    }
};