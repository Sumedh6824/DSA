class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        int vis[m][n];
        for(int i = 0; i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }

        int mt = 0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            mt = max(mt,t);
            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;

        return mt;
    }
};