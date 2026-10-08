class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i<m ; i++){
            for(int j = 0;j<n;j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};