class Solution {
    public int minSteps(String s, String t) {
        // 2-1 =  1
        // 1-2 = -1
        //{b:2, a:1}
        //{b:1, a:2}
        // 1+

        //{l:1, e:3, t:1, c:1, o:1, d:1} 
        //{ c:2, t:1, e:1} 
        // 1+2+1+1
        HashMap<Character,Integer> mapS = new HashMap();
        HashMap<Character,Integer> mapT = new HashMap();
        for(int i=0; i<s.length();i++){
            char curr = s.charAt(i);
            if(mapS.containsKey(curr)){
                int currCount = mapS.get(curr);
                mapS.put(curr, ++currCount);
            }
            else mapS.put(curr, 1);
        }
        for(int i=0; i<t.length();i++){
            char curr = t.charAt(i);
            if(mapS.containsKey(curr)){
                if(mapT.containsKey(curr)){
                    int currCount = mapT.get(curr);
                    mapT.put(curr, ++currCount);
                }
                else mapT.put(curr, 1);
            } 
        }
        int c = 0;
        for(Map.Entry<Character, Integer> entry : mapS.entrySet()){
            char currChar = entry.getKey();
            int currNum = entry.getValue();
            if(!mapT.containsKey(currChar)) c+=currNum;
            else if(mapT.containsKey(currChar) && currNum > mapT.get(currChar)) c+= (currNum - mapT.get(currChar) );
        }
        return c;
    }
}