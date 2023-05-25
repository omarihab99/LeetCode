class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        stack<vector<int>> stack;
        stack.push({0});
        int n = graph.size()-1;
        while(!stack.empty()){
            auto current_path = stack.top();
            stack.pop();
            int m = current_path.size()-1;
            int node = current_path[m];
            if(node == n) result.push_back(current_path);
            for(auto e:graph[node]){
                auto temp = current_path;
                temp.push_back(e);
                stack.push(temp);
            }
        }
        return result;
    }
};