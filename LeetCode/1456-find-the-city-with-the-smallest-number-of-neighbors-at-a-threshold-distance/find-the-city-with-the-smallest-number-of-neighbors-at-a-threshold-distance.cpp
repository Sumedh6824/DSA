class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        // for(auto it : edges){
        //     dist[it[0]][it[1]] = it[2];
        //     dist[it[1]][it[0]] = it[2];
        // }
        // for(int i = 0;i<n;i++){
        //     dist[i][i] = 0;
        // }
        // for(int k = 0;k<n;k++){
        //     for(int i = 0;i<n;i++){
        //         for(int j = 0;j<n;j++){
        //             if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
        //                 continue;
        //             }
        //         dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
        //         }
        //     }
        // }
        // int cntCity = n;
        // int cityNo = -1;
        // for(int city =0;city<n;city++){
        //     int cnt = 0;
        //     for(int adjCity = 0;adjCity <n;adjCity++){
        //         if(dist[city][adjCity] <= distanceThreshold){
        //             cnt++;
        //         }
        //     }
        //     if(cnt <= cntCity){
        //         cntCity = cnt;
        //         cityNo = city;
        //     }
        // }
        // return cityNo;


        // dijkstra algo
        vector<pair<int,int>> adj[n];
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int bestCity = -1, minCount = INT_MAX;

        for (int src = 0; src < n; src++) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, src});

            while (!pq.empty()) {
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if (dis > dist[node]) continue; // skip stale entries

                for (auto& it : adj[node]) {
                    int adjNode = it.first;
                    int edw = it.second;
                    if (dis + edw < dist[adjNode]) {
                        dist[adjNode] = dis + edw;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            int cnt = 0;
            for (int i = 0; i < n; i++)
                if (i != src && dist[i] <= distanceThreshold) cnt++;

            if (cnt <= minCount) {   // <= so ties go to the larger index
                minCount = cnt;
                bestCity = src;
            }
        }
        return bestCity;
    
    }
};