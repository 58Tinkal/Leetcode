class Solution {
public:
    double epsilon = 1e-6;
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) <= epsilon;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                vector<double> temp;
                for (int k = 0; k < nums.size(); k++) {
                    if (k == i || k == j)
                        continue;
                    temp.push_back(nums[k]);
                }
                double a = nums[i];
                double b = nums[j];
                vector<double> possibleVal = {a + b, a - b, b - a, a * b};
                if (abs(a) > 0.0) {
                    possibleVal.push_back(b / a);
                }
                if (abs(b) > 0.0) {
                    possibleVal.push_back(a / b);
                }
                for (double val : possibleVal) {
                    temp.push_back(val);
                    if (solve(temp)) {
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (auto& it : cards) {
            nums.push_back(1.0 * it);
        }
        return solve(nums);
    }
};