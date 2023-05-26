class Solution {
public:
    int bs(vector<int>&nums, int l, int r,int t){
        if(r>=l){
            int mid = (r+l)/2;
            if(nums[mid]==t) return mid;
            if(nums[mid] > t) return bs(nums, l, mid-1, t);
            return bs(nums, mid+1, r,t);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};