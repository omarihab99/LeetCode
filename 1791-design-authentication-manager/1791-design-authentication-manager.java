class AuthenticationManager {
    HashMap<String,Integer> map = new HashMap();
    int timeToLive;
    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
    }
    
    public void generate(String tokenId, int currentTime) {
        this.map.put(tokenId, currentTime);
    }
    
    public void renew(String tokenId, int currentTime) {
        if(this.map.containsKey(tokenId) && this.map.get(tokenId)+this.timeToLive > currentTime){
            this.map.put(tokenId, currentTime);
        }
    }
    
    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(Map.Entry<String,Integer> entry : map.entrySet()){
            if(this.map.get(entry.getKey())+this.timeToLive > currentTime){
                count++;
            }
        }
        return count;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */