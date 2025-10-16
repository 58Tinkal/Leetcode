class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, long long> freq;
        for (auto& x : nums) {
            int rem = ((x % value) + value) % value;
            freq[rem]++;
        }

        long long ans = 0;
        while (true) {
            int rem = ans % value;
            if (freq[rem] == 0)
                break;
            freq[rem]--;
            ans++;
        }
        return (int)ans;
    }
};
