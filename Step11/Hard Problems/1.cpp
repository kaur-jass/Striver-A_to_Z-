#include<bits/stdc++.h>
using namespace std;
class Twitter {
public:
    int time; 
    unordered_map<int, unordered_set<int>> follows;
    // <user, <followers>>
    unordered_map<int, vector<pair<int, int>>> tweets;
    // User -> List of {time, tweetId}
    Twitter() {
        time = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        follows[userId].insert(userId); // User always follows themselves 
        tweets[userId].push_back({time++,tweetId}); 
    }
    // priority_queue<vector<int>> heap; 
    // Elements of each vector pair consists of - 
    // {UserId, time, TweetId}

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> heap; 
        vector<int> ans; 
        follows[userId].insert(userId);

        // This is the Push Logic 

        for(int followee : follows[userId]){  // Check for every followee of follower 
            auto &userTweets = tweets[followee];  // Just pointing to the one tweet whose id is userId 
            if(!userTweets.empty()){
                int lastIdx = userTweets.size() -1;
                heap.push({
                    userTweets[lastIdx].first,    // Will Push Time 
                    userTweets[lastIdx].second,   // Will Push Tweet ID 
                    lastIdx -1,                   // We push lastIdx - 1 because after using the newest tweet, the next tweet is one step left in the list. or next Index to explore 
                    followee                       // Current userId 
                });
            }
        } 
        
        while(!heap.empty() && ans.size() < 10){
            vector<int> top = heap.top(); 
            heap.pop(); 
            int nextId = top[2];            // Lastindex-1 because we have already used the last index and now we want to explore the next index which is one step left in the list.
            int userId = top[3];
            ans.push_back(top[1]); 
            // We push next tweet of same user because That user may still have more recent tweets that belong in the top 10.
            if(nextId >= 0){
                auto &userTweets = tweets[userId];   
                if(!userTweets.empty()){
                    heap.push({                       // Now we will push the tweet which is behind the currebt tweet  means A3 if A4 is the latest tweet  
                        userTweets[nextId].first,    
                        userTweets[nextId].second,   
                        nextId - 1,                   
                        userId                     
                    });
                }
            }
        }
        return ans; 
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follows[followerId].erase(followeeId);
        }      
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

 int main() {
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);
    vector<int> param_2 = obj->getNewsFeed(1);
    for(int tweetId : param_2) {
        cout << tweetId << " ";
    }
    cout << endl;
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    param_2 = obj->getNewsFeed(1);
    for(int tweetId : param_2) {
        cout << tweetId << " ";
    }
    cout << endl;
    obj->unfollow(1, 2);
    param_2 = obj->getNewsFeed(1);
    for(int tweetId : param_2) {
        cout << tweetId << " ";
    }
    cout << endl;
    return 0;
}