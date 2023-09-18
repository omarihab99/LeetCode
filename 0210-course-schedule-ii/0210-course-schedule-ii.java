class Solution {
    //    3
    //   /  \   
    //  1    0
    //  \   /
    //    2
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[]  graph = new List[numCourses];
        String[] state = new String[numCourses];
        List<Integer> res = new ArrayList();
        for(int i=0;i<numCourses;i++){
            graph[i] = new ArrayList();
        }
        for(int prerequisite[] : prerequisites ){
            int u = prerequisite[1];
            int v = prerequisite[0];
            graph[u].add(v);
        }
        for(int i=0;i<numCourses;i++){
            if(hasCycle(graph,i,state,res)){
                return new int[0];
            }
        }
        int[] arr = new int[res.size()];
        for(int i=0; i< res.size(); i++){
            arr[res.size()-1-i] = res.get(i);
        }       
        return arr;
    }
    public boolean hasCycle(List<Integer>[] graph, int u, String[] state, List<Integer> res){
        if(state[u] == "visiting"){
            return true;
        }
        if(state[u] == "visited"){
            return false;
        }
        state[u] = "visiting";
        for(int v : graph[u]){
            if(hasCycle(graph, v, state, res)){
                return true;
            }
        }
        state[u] = "visited";
        res.add(u);
        return false;
    }
}