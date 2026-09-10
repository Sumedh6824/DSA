class Solution {
public:
    int countSmall(vector<vector<int>>& matrix, int n, int mid){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < n; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
        }

        while(low < high){
            int mid = low + (high - low)/2;
            int cnt = countSmall(matrix, n, mid);
            if(cnt < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};