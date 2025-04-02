class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int cnt = 0, s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            int deleted_subarray = s - k;
            cnt += m[deleted_subarray];
            m[s]++;
        }
        return cnt;
    }
};
