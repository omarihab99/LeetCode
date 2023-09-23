class Solution {
    public int maximumDetonation(int[][] bombs) {
        int max = 0;
        int n = bombs.length;
        boolean[] visited = new boolean[n];
        for(int i=0;i<n;i++){
          Arrays.fill(visited, false);
          max = Math.max(dfs(bombs,visited,i), max);
        }
        return max;
    }
    private int dfs(int[][] bombs, boolean[] visited, int currBomb){
      visited[currBomb] = true;
      long currRad = bombs[currBomb][2];
      int res = 1;
      for(int i=0;i<bombs.length;i++){
        if(visited[i] || i==currBomb) continue;
        long xDiff = (bombs[currBomb][0] - bombs[i][0]);
        long yDiff = (bombs[currBomb][1] - bombs[i][1]);
        long x = xDiff * xDiff;
        long y = yDiff * yDiff;
        long distance = x+y;
        if(distance<=(currRad * currRad)){
          res+=dfs(bombs,visited,i);
        }
      }
      return res;
    }
}