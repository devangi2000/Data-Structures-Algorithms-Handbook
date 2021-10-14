// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user,
//  and is able to see the 10 most recent tweets in the user's news feed.
// Implement the Twitter class:
// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
// Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed.
//  Each item in the news feed must be posted by users who the user followed or by the user themself. 
//  Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user 
// with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user
//  with ID followeeId.
// Example 1:
// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]
// Explanation
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
//  Constraints:
// 1 <= userId, followerId, followeeId <= 500
// 0 <= tweetId <= 104
// All the tweets have unique IDs.
// At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
class Twitter {
    private:
        unordered_map<int, set<int>> follower;
        unordered_map<int, vector<pair<int, int>>> tweets;
        long long time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    /* Retrieve the 10 most recent tweet ids in the user's news feed. 
    Each item in the news feed must be posted by users who the user followed or
    by the user herself. Tweets must be ordered from most recent to least recent.*/
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for(auto it = tweets[userId].begin(); it != tweets[userId].end(); ++it)
            maxHeap.push(*it);
        for(auto it1 = follower[userId].begin(); it1 != follower[userId].end(); ++it1){
            int user = *it1; // get target user
            for(auto it2 = tweets[user].begin(); it2 != tweets[user].end(); ++it2)
                maxHeap.push(*it2);
        }
        vector<int> res;
        while(maxHeap.size() > 0){
            res.push_back(maxHeap.top().second);
            if(res.size() == 10) break;
            maxHeap.pop();
        }
        return res;
    }
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follower[followerId].insert(followeeId);
    }
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follower[followerId].erase(followeeId);
        }
      }
};