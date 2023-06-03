class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int index=1;
        // for(int i=1; i<nums.size();i++){
        //     if(nums[i-1] != nums[i]) {
        //         nums[index] = nums[i];
        //         index++;
        //     }
        // }
        // return index;
        int i = 1, j=1;
        while(j<nums.size()){
            if(nums[j-1] != nums[j]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};