class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            int current = numbers[left] + numbers[right];
            if(current == target) break;
            if(current>target) right--;
            else left++;
        }
        return {left+1, right+1};
    }
};