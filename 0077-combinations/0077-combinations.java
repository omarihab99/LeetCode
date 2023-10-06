class Solution {
    List<List<Integer>> res = new ArrayList();
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> sub = new ArrayList();
        backtrack(sub,n,k,1);
        return res;
    }
    private void backtrack(List<Integer> sub, int n, int k, int i){
        if(sub.size()==k){
            res.add(new ArrayList(sub));
            return;
        }
        for(int j=i;j<=n;j++){
            sub.add(j);
            backtrack(sub,n,k,j+1);
            sub.remove(sub.size()-1);
        }
    }
}