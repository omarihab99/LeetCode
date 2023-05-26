class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        queue<int> queue;
        queue.push(0);
        int count=0;
        while(!queue.empty()){
            int current = queue.front();
            queue.pop();
            for(auto e : grid[current]){
                if(e<0) count++;
            }
            if(current < grid.size()-1) queue.push(current+1);
        }
        return count;
    }
};