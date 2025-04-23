class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        int c = 0;
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin(), nums.end(), nums[i]);
            while (it != nums.end()) {
                if (m[*it] > 0) {
                    c++;
                    m[*it]--;
                    break;
                }
                ++it;
            }
        }

        return c;
    }
};
