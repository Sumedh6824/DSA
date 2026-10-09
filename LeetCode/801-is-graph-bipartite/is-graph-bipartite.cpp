class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);

    for (int start = 0; start < V; start++) {
        if (color[start] != -1) continue;   
        color[start] = 0;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : graph[node]) {
                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    q.push(nei);
                } else if (color[nei] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}
};