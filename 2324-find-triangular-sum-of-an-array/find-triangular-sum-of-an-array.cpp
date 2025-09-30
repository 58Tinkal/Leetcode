class Solution {
public:
    void solve(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int x = (nums[i] + nums[i + 1]) % 10;
            temp.push_back(x);
        }
        nums = temp;
    }

    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {  
            solve(nums);
        }
        return nums[0];
    }
};
