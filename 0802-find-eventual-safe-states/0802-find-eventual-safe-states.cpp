class Solution {
public:
    bool checkCycle(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto& x: graph[node]) {
            if (!vis[x]) {
                if (checkCycle(x, graph, vis, pathVis, safe)) {
                    return true; 
                }
            }
            else if (pathVis[x]) {
                return true; 
            }
        }
        pathVis[node] = 0; 
        safe[node] = 1; 
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> safe(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                checkCycle(i, graph, vis, pathVis, safe);
            }
        }
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};