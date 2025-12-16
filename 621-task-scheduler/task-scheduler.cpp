class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for (auto it : tasks)
            m[it]++;
        priority_queue<int> q;
        for (auto it : m)
            q.push(it.second);
        int time = 0;
        while (!q.empty()) {
            vector<int> t;
            int cycle = n + 1;
            int i = 0;
            while (i < cycle && !q.empty()) {
                int cnt = q.top();
                q.pop();
                cnt--;
                if (cnt > 0) {
                    t.push_back(cnt);
                }
                time++;
                i++;
            }
            for (auto it : t)
                q.push(it);
            if (q.empty())
                break;
            time += cycle - i;
        }
        return time;
    }
};

// a,b,-,-,a,b,-,-,a,b