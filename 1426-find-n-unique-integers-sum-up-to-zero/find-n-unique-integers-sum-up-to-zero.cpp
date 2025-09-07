class Solution {
public:
    vector<int> sumZero(int n) {
        int x = n / 2;
        vector<int> ans;
        for (int i = 1; i <= x; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1)
            ans.push_back(0);
        return ans;
    }
};