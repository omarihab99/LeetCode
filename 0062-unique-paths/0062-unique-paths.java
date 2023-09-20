class Solution {
    public int uniquePaths(int m, int n) {
        int[][] grid = new int[m][n];
        for(int i=0;i<m;i++) Arrays.fill(grid[i], -1);
        return reachFinish(grid,m,n,0,0);
    }
    private int reachFinish(int[][] grid, int m, int n, int row, int col){
        if(row == m-1 || col == n-1){
            return 1;
        }
        if(grid[row][col] != -1){
            return grid[row][col];
        }
        return grid[row][col] = reachFinish(grid,m,n,row+1,col) + reachFinish(grid,m,n,row,col+1);
    }
}