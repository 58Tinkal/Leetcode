class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> freq;
        unordered_map<int, int> m;

        int maxVal = *max_element(begin(nums), end(nums)) + k;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            freq[l] += 1;
            freq[r + 1] -= 1;

            freq[nums[i]] += 0;
        }

        int prefix = 0;
        int ans = 1;

        for (auto it : freq) {
            int key = it.first;
            int f = it.second;

            prefix += f;
            int originalCount = m[key];
            int needConversion = prefix - originalCount;
            int res = min(needConversion, numOperations);

            ans = max(ans, originalCount + res);
        }

        return ans;
    }
};
