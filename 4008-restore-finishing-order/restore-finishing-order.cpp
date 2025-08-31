class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for (int i = 0; i < order.size(); i++) {
            for (auto it : friends) {
                if (it == order[i]) {
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};