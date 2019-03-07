class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //this graph is stored in an adjacent matrix, as graph
        vector<vector<int>> paths;
        vector<int> trace;
        int ind = 0;
        trace.push_back(0);
        dfs(graph,ind,trace,paths);
        return paths;
    }
    
    void dfs(vector<vector<int>>& graph, int ind, vector<int>& trace, vector<vector<int>>& paths)
    {
        if (ind==graph.size()-1)
        {
            paths.push_back(trace);
            return;
        }
        for (auto x : graph[ind])//x is the adjacent lists of node ind
        {
            trace.push_back(x);
            dfs(graph,x,trace,paths);
            trace.pop_back();
        }
    }
};
