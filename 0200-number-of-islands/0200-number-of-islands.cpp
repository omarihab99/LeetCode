class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    skipIslands(grid, i,j);
                }
            }
        }
        return island;
    }
    void skipIslands(vector<vector<char>>&grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || col < 0 || row > m-1 || col > n-1 || grid[row][col] == '0') return;
        grid[row][col] = '0';
        skipIslands(grid, row, col+1);
        skipIslands(grid, row, col-1);
        skipIslands(grid, row+1, col);
        skipIslands(grid, row-1, col);
    }
};