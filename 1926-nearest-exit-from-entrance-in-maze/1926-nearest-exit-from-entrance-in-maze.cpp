class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size();
        vector<pair<int,int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int startRow = entrance[0], startCol = entrance[1];
        maze[startRow][startCol] = '+';
        queue<array<int, 3>> queue;
        queue.push({startRow, startCol, 0});
        while(!queue.empty()){
            auto [currentRow, currentCol, currentDist] = queue.front();
            queue.pop();
            for(auto dir: directions){
                int nextRow = currentRow + dir.first , nextCol = currentCol + dir.second;
                if(0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols && maze[nextRow][nextCol] == '.'){
                    if(nextRow == 0 || nextRow == rows-1 || nextCol == 0 || nextCol == cols-1){
                        return currentDist + 1;
                    }
                    maze[nextRow][nextCol] = '+';
                    queue.push({nextRow, nextCol, currentDist+1});
                }
            }
        }
        return -1;
    }
};