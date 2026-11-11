class Solution {
public:
    bool f(int n){
        if(n == 1) return true;
        if(n%3 != 0) return false;
        int next = n / 3;
        return f(next);
    }
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        return f(n);
    }
};