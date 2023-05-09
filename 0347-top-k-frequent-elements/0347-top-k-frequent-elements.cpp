class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int> map;
        vector<int> out;
        for(int a: nums) map[a]++;
        for(auto el:map) freq[el.second].push_back(el.first);
        for(int i=nums.size(); i>0;i--){
            if(freq[i].size()){
                for(int j=0;j<freq[i].size();j++){
                    out.push_back(freq[i][j]);
                    k--;
                }
                if(!k) break;
            }
        }
        return out;
    }
};