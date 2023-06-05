class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        int x0 = coordinates[0][0], x1 = coordinates[1][0];
        int y0 = coordinates[0][1], y1 = coordinates[1][1];
        int deltaY = y1 - y0; 
        int deltaX = x1 - x0;
        for(int i=2; i<coordinates.size(); i++){
            int newY = coordinates[i][1];
            int newX = coordinates[i][0];
            if(((newY - y1) * deltaX) != ((newX - x1) * deltaY)) return false;
        }
        return true;
    }
    
};