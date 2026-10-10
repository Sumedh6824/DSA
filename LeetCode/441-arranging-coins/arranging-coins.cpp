class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1;
        long long high = n;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long sum = mid*(mid + 1) / 2;
            if(sum > n){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};