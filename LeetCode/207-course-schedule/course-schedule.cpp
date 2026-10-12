// class Solution {
// private:
//     bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         for (int it : adj[node]) {
//             if (!vis[it]) {
//                 if (dfsCheck(it, adj, vis, pathVis)) return true;
//             }
//             else if (pathVis[it]) {
//                 return true;
//             }
//         }
//         pathVis[node] = 0;
//         return false;
//     }

// public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>> adj(numCourses);
    //     for (auto& p : prerequisites) {
    //         adj[p[1]].push_back(p[0]);   // edge: b -> a
    //     }

    //     vector<int> vis(numCourses, 0), pathVis(numCourses, 0);

    //     for (int i = 0; i < numCourses; i++) {
    //         if (!vis[i]) {
    //             if (dfsCheck(i, adj, vis, pathVis)) return false; // cycle => can't finish
    //         }
    //     }
    //     return true;
    // }

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);   // edge: p[1] -> p[0]
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        return cnt == numCourses;   // true = no cycle
    }
};
// };