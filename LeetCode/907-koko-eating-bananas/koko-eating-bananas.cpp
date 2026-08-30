class Solution {
public:

    int maxElement(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i =0;i<n;i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }

    long long CalculateTotalHrs(vector<int> &v,int hourly){
        long long TotalH = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            TotalH += ceil((double)v[i] / (double)hourly);
        }
        return TotalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = maxElement(piles);
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long TotalH = CalculateTotalHrs(piles,mid);
            if(TotalH <= h){
                high = mid - 1;
            }
            else{
                low = mid+ 1;
            }
        }
        return low;
    }
};