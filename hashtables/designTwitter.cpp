class Twitter {
    unordered_map<int,unordered_set<int>>connections;
    unordered_map<int,vector<pair<int,int>>>userTweets;
    int time=0;
public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId,time});
        time+=1;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        for(int fid:connections[userId]){
            for(auto [tweetId,tweetTime]:userTweets[fid]){
                pq.push({tweetTime,tweetId});
            }
        }

        for(auto [tweetId,tweetTime]:userTweets[userId]){
            pq.push({tweetTime,tweetId});
        }

        int cnt=0;
        vector<int>ans;
        while(!pq.empty() and cnt!=10){
            auto [_,tweetId]=pq.top();
            pq.pop();
            ans.push_back(tweetId);
            cnt+=1;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        connections[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        connections[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
