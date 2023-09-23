class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum=0;
       for(int i=0; i< nums.size();i++){
           if(checkBinary(i,k)){
               sum+=nums.get(i);
           }
       }
        return sum;
    }
    public boolean checkBinary(int idx, int k){
        String binary = Integer.toBinaryString(idx);
        int num=0;
        for(int j=0;j<binary.length();j++){
            if(binary.charAt(j)=='1'){ num++;}
        }
        if(num==k) return true;
        return false;
    }
}