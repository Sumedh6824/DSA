class Solution {
private:
    void dfs(int node,vector<int> isConnectedLs[],vector<int>& vis){
        vis[node] = 1;
        for(auto it : isConnectedLs[node]){
            if(!vis[it]){
                dfs(it,isConnectedLs,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> isConnectedLs[n];

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    isConnectedLs[i].push_back(j);
                    isConnectedLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnectedLs,vis);
            }
        }
        return cnt;
    }
};