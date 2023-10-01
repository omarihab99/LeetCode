class Solution {
    public String originalDigits(String s) {
        int[] digit = new int[10];
        HashMap<Character,Integer> map = new HashMap();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<s.length();i++){
            char curr = s.charAt(i);
            if(map.containsKey(curr)){
                int count = map.get(curr);
                map.put(curr,++count);
            }
            else map.put(curr,1);
        }
        digit[0] = map.getOrDefault('z',0);
        digit[2] = map.getOrDefault('w',0);
        digit[4] = map.getOrDefault('u',0);
        digit[6] = map.getOrDefault('x',0);
        digit[8] = map.getOrDefault('g',0);
        digit[5] = map.getOrDefault('f',0)-digit[4];
        digit[7] = map.getOrDefault('s',0)-digit[6];
        digit[3] = map.getOrDefault('t',0)-digit[8]-digit[2];
        digit[1] = map.getOrDefault('o',0)-digit[4]-digit[2]-digit[0];
        digit[9] = map.getOrDefault('i',0)-digit[5]-digit[6]-digit[8];
        
        for(int i=0;i<10;i++){
            int f = digit[i];
            while(f>0){
                res.append(i);
                f--;
            }
        }
        return res.toString();
    }
}