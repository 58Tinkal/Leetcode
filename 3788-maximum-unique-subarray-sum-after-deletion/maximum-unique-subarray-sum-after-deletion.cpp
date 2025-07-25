class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> a;
         unordered_set<int> seen;

    for (int num : nums) {
        if(num > 0){
            if (seen.find(num) == seen.end()) { // If not seen before
            seen.insert(num);
            a.push_back(num);
        }
        }
    }
        if (a.size() == 0)
            return *max_element(nums.begin(), nums.end());
        int ans = -1e9;

        for (int i = 0; i < a.size(); i++) {
            int f[205] = {0};
            int s = 0;
            for (int j = i; j < a.size(); j++) {
                if (f[100 + a[j]] == 1)
                    break;
                f[100 + a[j]]++;
                s += a[j];
            }
            ans = max(ans, s);
        }
        return ans;
    }
};