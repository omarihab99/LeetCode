class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c=0, n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){dfs(isConnected, visited, i);c++;}
        }
        return c;
    }
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int currCity){
        visited[currCity] = true;
        for(int i=0; i<isConnected.size(); i++) if(!visited[i] && isConnected[currCity][i]) dfs(isConnected, visited, i);
        
    }
};