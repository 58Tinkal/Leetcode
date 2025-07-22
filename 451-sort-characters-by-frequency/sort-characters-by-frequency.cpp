class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> mx;
        map<char, int> m;
        for (auto it : s)
            m[it]++;
        for (auto it : m) {
            mx.push({it.second, it.first});
        }
        string str = "";
        while (!mx.empty()) {
            auto it = mx.top();
            mx.pop();
            for (int i = 0; i < it.first; i++) {
                str += it.second;
            }
        }
        return str;
    }
};