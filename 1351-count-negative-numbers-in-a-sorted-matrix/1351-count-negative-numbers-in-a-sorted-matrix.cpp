class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n = grid[0].size();
        int index = n-1;
        for(auto e : grid){
            while(index>=0 && e[index]<0) index--;
            count+= (n-index-1);
        }
        return count;
    }
};