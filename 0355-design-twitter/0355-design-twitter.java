class Twitter {
    int[] tweets;
    User[] users;
    int timestamp;
    class User{
        HashSet<Integer> following,followers;
        HashSet<int[]> myTweets;
        TreeSet<int[]> tweets;
        User(int id){
            this.followers = new HashSet();
            this.following = new HashSet();
            this.myTweets = new HashSet();
            this.tweets = new TreeSet<>((a,b) -> (b[1] - a[1]));
            this.following.add(id);
        }

    }
    public Twitter() {
        this.tweets = new int[10001];
        this.users = new User[501];
        this.timestamp=0;
    }
    
    public void postTweet(int userId, int tweetId) {
        this.tweets[tweetId] = userId;
        if(users[userId] == null){
            User user = new User(userId);
            users[userId] = user;
        }
        User currentUser = users[userId];
        int[] newPost = {tweetId, this.timestamp++};
        currentUser.tweets.add(newPost);
        currentUser.myTweets.add(newPost);
        for(int follower : currentUser.followers){
            users[follower].tweets.add(newPost);
        }
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> newsFeed = new ArrayList(10);
        if(users[userId] == null) return newsFeed;
        for(int[] userTweet : users[userId].tweets){
            int tId = userTweet[0];
            int uId = this.tweets[tId];
            if(users[userId].following.contains(uId)) newsFeed.add(tId);
            if(newsFeed.size()==10) break;
        }
        return newsFeed;
    }
    
    public void follow(int followerId, int followeeId) {
        User userFollower = users[followerId];
        User userFollowee = users[followeeId];
        if(userFollower == null){
            userFollower = new User(followerId);
            users[followerId] = userFollower;
        }
        if(userFollowee == null){
            userFollowee = new User(followeeId);
            users[followeeId] = userFollowee;
        }
        userFollower.following.add(followeeId);
        userFollowee.followers.add(followerId);
        userFollower.tweets.addAll(userFollowee.myTweets);
    }
    
    public void unfollow(int followerId, int followeeId) {
        User userFollower = users[followerId];
        User userFollowee = users[followeeId];
        userFollower.following.remove(followeeId);
        userFollowee.followers.remove(followerId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */