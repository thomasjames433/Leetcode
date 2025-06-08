class Twitter {

private:
int timestamp;
unordered_map<int, unordered_set<int>>followers;
unordered_map<int,vector<pair<int,int>>>tweets;

public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        followers[userId].insert(userId);

        for (auto it:followers[userId]){

            for (auto tw:tweets[it]){
                pq.push(tw);
                if(pq.size()>10)
                    pq.pop();
            }
        }
        vector<int>ret;
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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