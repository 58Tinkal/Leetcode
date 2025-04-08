class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        while (true) {
            unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size()) {
                return ops; // all distinct
            }
            if (nums.size() <= 3) {
                return ops + 1; // remove all
            }
            // remove first 3 elements
            nums.erase(nums.begin(), nums.begin() + 3);
            ops++;
        }
    }
};
