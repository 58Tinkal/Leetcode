class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;

        vector<int> freqArr(maxVal + 2, 0);
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;

            int l = max(nums[i] - k, 0);
            int r = min(nums[i] + k, maxVal);

            freqArr[l]++;
            freqArr[r + 1]--;
        }

        int ans = 1;

        for (int i = 0; i <= maxVal; i++) {
            if (i > 0)
                freqArr[i] += freqArr[i - 1];

            int originalCount = m[i];
            int needConversion = freqArr[i] - originalCount;
            int res = min(needConversion, numOperations);
            ans = max(ans, originalCount + res);
        }

        return ans;
    }
};
