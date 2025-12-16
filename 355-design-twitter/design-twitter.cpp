class Twitter {
public:
    map<int, vector<pair<int, int>>> tweets;
    map<int, set<int>> following;
    int time = 1;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time++});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto t : tweets[userId]) {
            if (pq.size() == 10) {
                if (pq.top().first < t.second) {
                    pq.pop();
                    pq.push({t.second, t.first});
                }
            } else {
                pq.push({t.second, t.first});
            }
        }

        for (auto followee : following[userId]) {
            for (auto t : tweets[followee]) {
                if (pq.size() == 10) {
                    if (pq.top().first < t.second) {
                        pq.pop();
                        pq.push({t.second, t.first});
                    }
                } else {
                    pq.push({t.second, t.first});
                }
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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