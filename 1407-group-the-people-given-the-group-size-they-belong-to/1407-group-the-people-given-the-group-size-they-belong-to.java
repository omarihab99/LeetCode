class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        HashMap<Integer, List<Integer>> map = new HashMap();
        List<List<Integer>> res = new ArrayList();
        for(int i=0;i<groupSizes.length;i++){
            int size = groupSizes[i];
            List<Integer> group;
            if(map.containsKey(size)) group = map.get(size);
            else group = new ArrayList();
            group.add(i);
            if(group.size() == size){
                res.add(group);
                map.remove(size);
            }
            else map.put(size,group);
        }
        return res;  
    }
}