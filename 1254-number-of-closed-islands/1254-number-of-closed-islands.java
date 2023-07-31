class Solution {
    public int closedIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && !visited[i][j] && bfs(i,j,m,n,grid,visited)){
                    count++;
                }
            }
        }
        return count;
    }
    public boolean bfs(int x, int y, int m, int n, int[][] grid, boolean[][] visited){
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x,y});
        visited[x][y] = true;
        boolean closed = true;
        int[][] dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!queue.isEmpty()){
            int[] current = queue.poll();
            x = current[0];
            y = current[1];
            for(int i=0;i<dirs.length;i++){
                int row = x + dirs[i][0];
                int col = y + dirs[i][1];
                if(row<0 || row>=m || col<0 || col >=n){
                    closed=false;
                }
                else if(grid[row][col]==0 && !visited[row][col]){
                    visited[row][col] = true;
                    queue.offer(new int[]{row,col});
                }
            }
        }
        return closed;
    }
}