class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<Integer>[] grid = new List[n];
        for(int i=0;i<n;i++){
            grid[i] = new ArrayList();
        }
        for(int[] edge:edges){
            int f = edge[0];
            int s = edge[1];
            grid[f].add(s);
            grid[s].add(f);
        }  
        return valid(new boolean[n], grid,n,source,destination);
    }
    public boolean valid( boolean[] visited, List<Integer>[] grid, int n, int s, int d){
        if(s==d){
            return true;
        }
        visited[s] = true;
        for(int v : grid[s]){
            if(!visited[v] && valid(visited, grid,n,v,d)){
                return true;
            }
        }
        return false;
    }
}