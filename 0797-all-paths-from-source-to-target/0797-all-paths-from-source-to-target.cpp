class Solution {
public:
    void findAllPaths(vector<vector<int>>& graph, int currNode,vector<bool>& visited, int n, vector<int>& currPath,
                      vector<vector<int>>& res) {
        if (currNode == n - 1){
             res.push_back(currPath);
        return;
        }
        if (visited[currNode] == true) return;

        visited[currNode] = true;
        for (auto neighbour : graph[currNode]) {
            currPath.push_back(neighbour);
            findAllPaths(graph, neighbour, visited, n, currPath, res);
            currPath.pop_back();
        }
        visited[currNode] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> currPath;
        int n= graph.size();
        vector<bool> visited(n);

        currPath.push_back(0);
        findAllPaths(graph, 0, visited, n, currPath, res);
        return res;
    }
};