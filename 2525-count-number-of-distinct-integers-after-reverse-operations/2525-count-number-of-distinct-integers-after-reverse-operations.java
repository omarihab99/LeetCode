class Solution {
    public int countDistinctIntegers(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> map = new HashMap();
        for(int num : nums){
          map.put(num,1);
        }
        for(int i=0;i<n;i++){
          int number = nums[i];
          int newNum=0;
          while(number!=0){
            int temp = number%10;
            newNum = newNum*10+temp;
            number /=10;
          }
          map.put(newNum,1);
        }
        return map.size();
    }
}