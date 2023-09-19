class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length+1;
        int[] e = new int[n];
        for(int[] edge: edges){
            e[edge[0]-1]++;
            e[edge[1]-1]++;
        }
        for(int i=0;i<e.length;i++){
            if(e[i]==n-1){
                return i+1; 
            }
        }
        return 0;
    }
}