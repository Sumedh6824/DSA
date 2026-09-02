class Solution {
public:
    
    int SplitCounter(vector<int>& arr, int val){
        int cntSplit = 1;
        long long Splitval = 0;
        for(int i = 0;i<arr.size();i++){
            if(Splitval + arr[i] <= val){
                Splitval += arr[i];
            }
            else{
                cntSplit++;
                Splitval = arr[i];
            }
        }
        return cntSplit;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end()) , high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = (low + high) / 2;
            int NoOfSplits = SplitCounter(nums,mid);
            if(NoOfSplits > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};