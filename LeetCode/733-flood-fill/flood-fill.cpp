class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int iniColor, int color, int delRow[], int delCol[]){
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        for(int i = 0; i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                dfs(nrow,ncol,image,ans,iniColor,color,delRow,delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        dfs(sr,sc,image,ans,iniColor,color,delRow,delCol);
        return ans;
    }
};