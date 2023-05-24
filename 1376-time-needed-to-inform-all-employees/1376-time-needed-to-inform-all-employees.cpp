class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> map;
        int total;
        for(int i=0;i < manager.size();i++){
            if(manager[i]>=0) map[manager[i]].push_back(i);
        }
        stack<pair<int,int>> stack;
        stack.push({headID, 0});
        while(!stack.empty()){
            auto current = stack.top();
            int currentHead = current.first;
            int currentTime = current.second;
            stack.pop();
            currentTime += informTime[currentHead];
            total = max(currentTime, total);
            auto employees = map[currentHead];
            for(auto e : employees){
                stack.push({e, currentTime});
            }
        }
        
        return total;
    }
};