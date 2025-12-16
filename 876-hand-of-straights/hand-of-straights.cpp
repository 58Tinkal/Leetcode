class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> m;
        for (auto it : hand)
            m[it]++;
        auto it = m.begin();
        while (it != m.end()) {
            if (it->second == 0) {
                it++;
                continue;
            }
            int start = it->first;
            int count = it->second;
            for (int i = 0; i < groupSize; i++) {
                if (m[start + i] < count)
                    return false;
                m[start + i] -= count;
            }
            it++;
        }
        return true;
    }
};