class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<vector<int>> queue;
        queue.push({0,0,1});
        grid[0][0] = 1;
        vector<vector<int>> dirs = {
            {1,0}, {0,1}, {0,-1}, {-1,0},{1,1},{-1,-1},{-1,1},{1,-1}  
        };
        while(!queue.empty()){
            auto current = queue.front();
            queue.pop();
            int currentRow = current[0];
            int currentCol = current[1];
            int currentDist = current[2];
            if(currentRow == n-1 && currentCol == n-1) return currentDist;
            for(auto dir : dirs){
                int nextRow = dir[0] + currentRow;
                int nextCol = dir[1] + currentCol;
                if(nextRow >= 0 && nextRow <= n-1 && nextCol >= 0 && nextCol <= n-1 && grid[nextRow][nextCol] == 0){
                    grid[nextRow][nextCol] = 1;
                    queue.push({nextRow, nextCol, currentDist+1});
                }
            }
        }
        return -1;
    }
};