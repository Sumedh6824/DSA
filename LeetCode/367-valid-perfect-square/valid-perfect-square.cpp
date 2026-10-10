class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0;
        long long high = num;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long sq = (mid*mid);
            if(sq < num){
                low = mid + 1; 
            }
            else if(sq > num){
                high = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};