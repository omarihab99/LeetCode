class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int c = target - nums[i];
            if(map.find(c) != map.end()) {res = {i, map[c]};break;}
            map[nums[i]] = i;
        }
        return res;
    }
};