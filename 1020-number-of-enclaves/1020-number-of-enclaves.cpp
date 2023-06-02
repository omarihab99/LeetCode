class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i=0; i<m ; i++){
            if(grid[i][0] == 1 && !visited[i][0]) dfs(grid, visited, i, 0);
            if(grid[i][n-1] == 1 && !visited[i][n-1]) dfs(grid, visited, i, n-1);
        }
        for(int i=0; i<n ; i++){
            if(grid[0][i] == 1 && !visited[0][i]) dfs(grid, visited, 0, i);
            if(grid[m-1][i] == 1 && !visited[m-1][i]) dfs(grid, visited, m-1, i);
        }
        for(int i=0; i<m ; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]) count++;
            }
        }
        
        return count;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row > m-1 || col > n-1 || grid[row][col]==0 || visited[row][col]) return;
        visited[row][col]=true;
        dfs(grid, visited, row, col+1);
        dfs(grid, visited, row, col-1);
        dfs(grid, visited, row+1, col);
        dfs(grid, visited, row-1, col);
    }
};