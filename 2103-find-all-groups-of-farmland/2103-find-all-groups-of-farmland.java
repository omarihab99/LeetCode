class Solution {
    public int[][] findFarmland(int[][] land) {
        int rows = land.length;
        int cols = land[0].length;
        List<int[]> res = new ArrayList();
        for(int i=0;i<rows;i++){
            for(int j=0; j<cols;j++){
                if(land[i][j] == 1){
                    int x = i;
                    int y = j;
                    while(y < cols && land[i][y]==1){
                        y++;
                    }
                    while(x < rows && land[x][j]==1){
                        land[x][j] = y-j+1;
                        x++; 
                    }
                    res.add(new int[]{i,j,x-1,y-1});
                }
                if(land[i][j] > 1){
                    j += land[i][j]-1;
                }
            }
        }
        return res.toArray(new int[0][]);
    }
    
}