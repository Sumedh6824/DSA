class Solution {
public:
    // int maxEl(vector<int>& v){
    //      int n = v.size();
    //      int max = INT_MIN;
    //     for(int i = 0; i< n;i++){
    //         max = max(max,v[i]);
    //     }
    //     return max;
    //}
    int weightSum(vector<int>& ve){
        int n = ve.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum = sum + ve[i];
        }
        return sum;
    }
    int FindDays(vector<int>& arr, int cap){
        int days = 1 , load = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] + load > cap){
                days = days + 1;
                load = arr[i];
            }
            else{
                load += arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()) , high = weightSum(weights);
        while(low <= high){
            int mid = (low + high) / 2;
            if(FindDays(weights,mid) <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};