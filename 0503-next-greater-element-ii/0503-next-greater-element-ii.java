class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Stack<Integer> stack = new Stack();
        for(int i=2*n-1; i>=0;i--){
            while(!stack.empty() && nums[i%n] >= nums[stack.peek()]){
                stack.pop();
            }
            res[i%n] = stack.empty() ? -1 : nums[stack.peek()];
            stack.push(i%n);
        }
        return res;
    }
}