class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, long long> m;
        long long ans = 0;
        long long cnt = 0;
        long long l = 0;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            if (m[nums[i]] > 1)
                cnt += m[nums[i]] - 1;
            if (cnt >= k)
                ans += n - i;
            while (cnt >= k) {
                m[nums[l]]--;
                if (m[nums[l]] > 0)
                    cnt -= m[nums[l]];
                l++;
                if (cnt >= k)
                    ans += n - i;
            }
        }
        cout << cnt << endl;
        if (cnt >= k)
            ans++;
        while (cnt >= k) {
            if (m[nums[l]] > 0)
                m[nums[l]]--;
            if (m[nums[l]] > 0)
                cnt -= m[nums[l]];
            l++;
            if (cnt >= k)
                ans += 1;
        }
        if (cnt >= k)
            ans++;
        return ans;
    }
};