class Solution {
public:
    // bool f(int n){
    //     if(n == 1) return true;
    //     if(n%3 != 0) return false;
    //     int next = n / 3;
    //     return f(next);
    // }
    // bool isPowerOfThree(int n) {
    //     if(n <= 0) return false;
    //     return f(n);
    // }

    bool isPowerOfThree(int n){
        if(n <= 0) return false;
        while(n%3 == 0) n = n/3;
        return n == 1;
    }
};