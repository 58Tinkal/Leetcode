

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using ll = long long;

        priority_queue<int, vector<int>, greater<int>> freeRooms;        // room indices
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> busy; // {endTime, room}

        for (int i = 0; i < n; ++i) freeRooms.push(i);

        vector<ll> cnt(n, 0);
        sort(meetings.begin(), meetings.end());                        

        for (auto &mt : meetings) {
            ll start = mt[0], end = mt[1], duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                cnt[room]++;
                busy.push({end, room});
            } else {
                auto [prevEnd, room] = busy.top();
                busy.pop();
                cnt[room]++;
                busy.push({prevEnd + duration, room}); 
            }
        }
        
        int best = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[best]) best = i;
        return best;
    }
};
