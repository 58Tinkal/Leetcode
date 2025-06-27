class Solution {
public:
    set<int> s = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                  43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(102, 0);
        for (auto& it : nums) {
            freq[it]++;
        }
        for (auto it : freq) {
            if (it != 0 && s.find(it) != s.end()) {
                return true;
            }
        }
        return false;
    }
};