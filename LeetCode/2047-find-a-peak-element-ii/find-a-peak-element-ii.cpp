class Solution {
public:
    int maxRowIndex(vector<vector<int>>& mat, int m, int n, int col){
        int index = -1;
        int maxValue = -1;
        for(int i = 0; i < m; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;   

        while(low <= high){
            int mid = (low + high) / 2;
            int rowIdx = maxRowIndex(mat, m, n, mid);

            int left  = (mid - 1 >= 0) ? mat[rowIdx][mid - 1] : -1;
            int right = (mid + 1 < n) ? mat[rowIdx][mid + 1] : -1;

            if(mat[rowIdx][mid] > left && mat[rowIdx][mid] > right){
                return {rowIdx, mid};
            }
            else if(mat[rowIdx][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};