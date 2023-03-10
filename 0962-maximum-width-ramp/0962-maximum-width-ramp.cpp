class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int r=0;
        for(int i=0;i<nums.size();i++) 
            if(s.empty() || nums[i] < nums[s.top()]) 
                s.push(i);
        for(int i=nums.size()-1;i>r;i--)
            while(!s.empty() && nums[i] >= nums[s.top()]){
                r = max(r, i-s.top());
                s.pop();
            }
        return r;
    }
};