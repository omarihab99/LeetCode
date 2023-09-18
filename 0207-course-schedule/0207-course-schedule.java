class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<Integer>[] graph = new List[numCourses];
        String[] state = new String[numCourses];
        for(int i=0;i<numCourses; i++){
            graph[i] = new ArrayList();
        }
        for(int i=0; i<prerequisites.length;i++){
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];
            graph[first].add(second);
        }
        for(int i=0;i<numCourses;i++){
            if(hasCycle(graph,i,state)){
                return false;
            }
        }
        return true;
    }
    public boolean hasCycle(List<Integer>[] graph, int first, String[] state){
        if(state[first] == "visiting"){
            return true;
        }
        if(state[first] == "visited"){
            return false;
        }
        state[first] = "visiting";
        for(int v : graph[first]){
            if(hasCycle(graph, v,state)){
                return true;
            }
        }
        state[first] = "visited";
        return false;
    }
}