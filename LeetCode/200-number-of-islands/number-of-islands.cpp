class Solution {
private:
    void bfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    if(abs(delrow) + abs(delcol) != 1) continue;
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt = 0;
        for(int row = 0; row < m ; row++){
            for(int col = 0; col < n; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};